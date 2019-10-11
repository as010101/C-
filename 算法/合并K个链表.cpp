//此算法要求k个链表递增
//template <class T, class Container = vector<T>,
 //      class Compare = less<typename Container::value_type> > class priority_queue;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode vHead(1) ;   //leetcode 没有关于()的构造器，所以要有参数，这个节点用于记录合并后节点的head
        ListNode *p = &vHead;  //这个用于合并链表时，总是指在合并链表的尾端
        auto cmp=[](const ListNode * a,const ListNode *b ){return a->val>b->val;};//此处用*不用&,因为传进来的是
                                                                                  //指针，没有引用指针这种说法
                                                                                //只有指针的引用
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>   heap(cmp);  //优先队列默认使用less 得到的是
                                                                                //大根堆，即输出的元素会是降序
                                                                                 //故此处要改适配算法

        //第一次优先队列里面的都是list的头结点，在头结点中选择最大的弹出
          for (ListNode *node : lists) if(node)heap.push(node);
        while(!heap.empty())
        {
            ListNode *temp=heap.top();
            heap.pop();
            p->next=temp;     //不要老思考，要记住这种处理方式，当新得出一个节点时
                                //,一般地，会给一个移动指针以指向之，然后再让当前移动指针往后移动
            if(temp->next){heap.push(temp->next);}  //思路是先将k个有序链表的头结点推入堆中，进行排序，得到
                                                    //最小节点，然后对得到最小节点相对应的那个链表进行处理，即
                                                    //将下一个节点推入堆，重新进行堆排序，继续循环
            p=p->next;
        
            
        }
        return vHead.next;
    }

};
