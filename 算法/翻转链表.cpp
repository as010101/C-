
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
    ListNode *pre=nullptr;    //此处赋值为nullptr是为了翻转后尾指针指向nullptr
    ListNode *cur=head;
        while(cur!=nullptr)
        {
        ListNode * temp=cur->next;
            cur->next=pre;    //要被赋值的放在左边
            pre=cur;
            cur=temp;
        
            }
        return pre;
    }
};


//链表的翻转需要两个额外指针，一个记录前驱，一个记录当前，如果没有这两者，一次指向之后，无法向后执行


2.头插法    （返回一个新的链表结构，但是是倒序的）
1 2 3 4 5
1
21
321
头插法的新增节点在头部，尾插发的新增节点在尾部



头插
head->next=null   假如head不作为头结点(即会存储数据)，则可以实施以下算法，倘若已给头结点L


{
node->next=head
head=node
}


L->next=null
{
node->next=L->next;
L->next=node;
}


尾插    head作不作为头结点都是以下算法

要先保存head,如果要返回链表的话  List *p=head;

head->Next=node
head=node  //这一步使得两个指针指向同一节点，即head 与 node，其中head会每次往后移，node每次会新增
不改变表结构，递归也可以实现逆向输出



逆置
        ListNode * temp=cur->next;
            cur->next=pre;    //要被赋值的放在左边
            pre=cur;
            cur=temp;

3.递归

递归找到链表尾端，再从尾部一个一个反转，同双指针一样，都会改变链表结构



