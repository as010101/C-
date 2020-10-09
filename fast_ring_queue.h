/*************************************************
Copyright:CFSC
Author: Souleep
Date:2020-06-02
Description:通过CAS/Memory_Order分别实现无锁消息队列
**************************************************/
/*todo:linux kernel的kfifo机制好像更优雅*/
#ifndef __LFQUEUE_H__
#define __LFQUEUE_H__
#include <thread>
#include <iostream>
#include <atomic>
#include <stdint.h>
#define CAS2(obj, expected, desired) std::atomic::atomic_compare_exchange_weak(obj, expected, desired);
#ifdef WIN32
#define CAS(ptr, oldvalue, newvalue) InterlockedCompareExchange(ptr, newvalue, oldvalue)
#else
#define CAS(ptr, oldvalue, newvalue) __sync_val_compare_and_swap(ptr , oldvalue , newvalue)
#endif
#include<mutex>

template<typename ELEM_TYPE>
class LockFreeQueue
{
public:
	LockFreeQueue(int capicity) : capicity_(capicity), header_(0), tailer_(0), guard_(0)
	{
		if (capicity_ < 4) { capicity_ = 4; }
		lf_queue_ = new ELEM_TYPE * [capicity_];
		for (int i = 0; i < capicity_; i++)
			lf_queue_[i] = NULL;
	}
	~LockFreeQueue() { if (lf_queue_) { delete[] lf_queue_; } }
public:
	enum QStatus {
		Empty,
		Full,
		Normal,
		Unknown
	};
	bool isempty() { return header_ == guard_; }
	bool isfull() { return (internal_index(tailer_ + 1)) == header_; }
	int internal_index(int v) { return (v % capicity_); }
	bool enqueue(ELEM_TYPE* item)
	{
		int temp, guard;
		ASSERT(item);
		do
		{
			// fetch tailer_ first and then judge isfull, else encounter concurrent problem
			temp = tailer_;
			guard = guard_;
			if (isfull())
			{
				return false;
			}
			// cross operate
			if (CAS(&tailer_, temp, internal_index(temp + 1)) == temp)
			{
				lf_queue_[temp] = item;
				// update the guard_ for the max dequeue item
				CAS(&guard_, guard, internal_index(guard + 1));
				break;
			}
			else
			{
				//std::cout << "enqueue Cas failure one times" << std::endl;
			}
		} while (true);
		return true;
	}
	template<typename ELEM_TYPE>
	bool dequeue(ELEM_TYPE** item)
	{
		int temp;
		do
		{
			// fetch header first and then judge isempty, else encounter concurrent problem
			temp = header_;
			*item = NULL;
			if (isempty())
			{
				return false;
			}
			// cross operate CAS failure
			*item = lf_queue_[temp];
			if (CAS(&header_, temp, internal_index(temp + 1)) == temp)
			{
				// some producer lock one slot, but doesn't push back
				// while (!lf_queue_[temp])
				// {
				// std::this_thread::yield();
				// }
				//*item = lf_queue_[temp];
				lf_queue_[temp] = NULL;
				break;
			}
			else
			{
				//std::cout << "dequeue Cas failure one times" << std::endl;
			}
		} while (true);
		return true;
	}
private:
	ELEM_TYPE** lf_queue_;
	int capicity_;
#ifdef WIN32
	long header_;
	long tailer_;
	long guard_;
	// header <= guard <= tailer
#else
	int header_;
	int tailer_;
	int guard_;
//	int          header_;
//	int          tailer_;
//	int          guard_;        // header <= guard <= tailer
#endif
};



//空锁
struct NullMutex
{
	void lock() {}
	void unlock() {}
};


#define XIXI_CACHELINE_SIZE  64
//通过内存序实现双锁链表:类似于原子变量但要强于原子变量
//双锁链表(头尾锁):如果单进单出，使用空锁实现无锁队列
template<typename VALUE_TYPE, typename PUSH_MUTEX_TYPE = std::mutex, typename POP_MUTEX_TYPE = std::mutex>
class NonBlockingQueue
{
public:
	NonBlockingQueue(const NonBlockingQueue&) = delete;
	NonBlockingQueue& operator= (const NonBlockingQueue&) = delete;

	typedef VALUE_TYPE value_type;
private:

	struct Node
	{
		//value_type   data;
		char data[sizeof(value_type)];
		Node* next;
	};

	Node* m_head; //队列头        
	Node* m_freeTail;

	char padding1[XIXI_CACHELINE_SIZE - sizeof(Node*) * 2];
	Node* m_tail; //队列尾    
	Node* m_free; //

	PUSH_MUTEX_TYPE m_push_mutex;
	POP_MUTEX_TYPE  m_pop_mutex;

public:

	NonBlockingQueue(int init_node_num = UINT16_MAX)
	{

		Node* pNode = allocNode();
		if (pNode)
		{
			pNode->next = NULL;
		}
		m_head = m_tail = pNode;

		pNode = allocNode();
		if (pNode)
		{
			pNode->next = NULL;
		}
		m_free = m_freeTail = pNode;

		for (int i = 0; i < init_node_num; i++)
		{
			pushNode(allocNode());
		}

	}

	~NonBlockingQueue()
	{
		Node* pNode = NULL;
		while (m_head)
		{
			pNode = m_head;
			m_head = m_head->next;

			VALUE_TYPE* obj = (VALUE_TYPE*)pNode->data;
			obj->~VALUE_TYPE();

			freeNode(pNode);
		}

		m_tail = NULL;

		while (m_free)
		{
			pNode = m_free;
			m_free = m_free->next;
			freeNode(pNode);
		}
	}

	bool push(const VALUE_TYPE& value)
	{
		m_push_mutex.lock();
		Node* pNode = popNode();
		if (pNode)
		{
			new (pNode->data) VALUE_TYPE(value);

			pNode->next = NULL;

			Node* new_tail = m_tail;
			this->m_tail = pNode;

			std::atomic_thread_fence(std::memory_order_release);

			new_tail->next = pNode;

			m_push_mutex.unlock();
			return true;
		}
		m_push_mutex.unlock();
		return false;
	}

	bool pop(VALUE_TYPE& value)
	{
		m_pop_mutex.lock();
		Node* pNode = m_head;

		Node* new_head = pNode->next;
		if (new_head)
		{
			std::atomic_thread_fence(std::memory_order_acquire);

			VALUE_TYPE* obj = (VALUE_TYPE*)new_head->data;
			value = *obj;
			obj->~VALUE_TYPE();


			m_head = new_head;
			pushNode(pNode);
			m_pop_mutex.unlock();
			return true;
		}

		m_pop_mutex.unlock();

		return false;
	}

private:
	//内存分配一个节点
	Node* allocNode()
	{
		return new Node();
	}

	//归还节点内存
	void freeNode(Node* pNode)
	{
		delete pNode;
	}

	//从空闲节点池获取一个节点
	Node* popNode()
	{
		Node* pNode = m_free;

		Node* new_head = pNode->next;

		if (new_head)
		{
			std::atomic_thread_fence(std::memory_order_acquire);

			m_free = new_head;
		}
		else
		{
			pNode = allocNode();
		}
		return pNode;
	}

	//把一个节点放回空闲列表
	void pushNode(Node* pNode)
	{
		Node* new_tail = m_freeTail;
		pNode->next = NULL;


		m_freeTail = pNode;

		std::atomic_thread_fence(std::memory_order_release);

		new_tail->next = pNode;
	}
};

#endif