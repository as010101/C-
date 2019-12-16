#include "stdio.h"
#include "stdlib.h"

#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int status;
typedef int ElemType;
typedef status (*fp)(ElemType a,ElemType b);

typedef struct QNode{
	ElemType data;
	QNode* next;
}QNode;

typedef struct Queue
{
	// 缓存个数
	int nums;
	// 当前个数
	int totals;
	// 头结点
	QNode *front;
	// 尾结点
	QNode *rear;
}Queue;

status InitQueue(Queue &Q);
status Locate_QNode(Queue Q,ElemType e,fp compare);
status equal(ElemType a,ElemType b);
status Add_QNode(Queue &Q,ElemType newQ,ElemType &oldQ);
status EnQueue(Queue &Q,ElemType e);
status DeQueue(Queue &Q,ElemType e);


status InitQueue(Queue &Q){
	int nums;
	printf("please input cache nums:");
	scanf("%d",&nums);
	if(nums<1) return ERROR;
	Q.nums = nums;
	Q.totals = 0;
	Q.front = (QNode*)malloc(sizeof(QNode));
	Q.front->next =  NULL;
	Q.rear = Q.front;
	return OK;
}

// 查找队列是否有对应的缓存
status Locate_QNode(Queue Q,ElemType e,fp compare){
	QNode *q1=Q.front;
	while(q1){
		if(compare(q1->data,e)) return OK;
		q1 = q1->next;
	}
	return ERROR;
}

status Add_QNode(Queue &Q,ElemType newQ,ElemType &oldQ){
	// 在尾部添加新的结点
	EnQueue(Q,newQ);
	// 缓存个数尚未满，个数增加
	if(Q.totals<Q.nums){
		Q.totals++;
	}else{
	// 缓存个数已满，去除头结点
		DeQueue(Q,oldQ);
	}
	return OK;
}

status EnQueue(Queue &Q,ElemType e){
	QNode *p;
	p = (QNode*)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}

status DeQueue(Queue &Q,ElemType e){
	QNode *p;
	if(!Q.front->next) return ERROR;
	p = Q.front->next;
	Q.front->next = p->next;
	e = p->data;
	free(p);
	// 最后一个结点了
	if(!Q.front->next) Q.rear = Q.front;
	return OK;
}

status equal(ElemType a,ElemType b){
	return a==b?OK:ERROR;
}

int main(int argc, char const *argv[])
{
	// 测试缓存页面队列,不同数字代表不同的缓存页面
	ElemType a[] = { 1,2,3,4,2,1,5,6,2,1,2,3,7,6,3,2,1,2,3,6};
	int count = sizeof(a)/sizeof(a[0]);
	// j为置换次数，temp为置换出来的页面
	int i, j=0,temp;
	Queue Q;
	InitQueue(Q);
	for(i = 0; i < count;i++){
		if(!Locate_QNode(Q,a[i],equal)){
			Add_QNode(Q,a[i],temp);
			j++;
		}
	}
	printf("页面置换次数%d\n",j);
	return 0;
}