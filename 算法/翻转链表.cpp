
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









//注意dummy是防止头结点被改变指向后，没有节点指向新的头结点
//pre的作用是当链表只有两个元素时，for里面依然可以跑通，否则t会是nullptr
//for里面   前两步  先保存curr的next,然后依靠保存的next让curr指向第三个节点
//后两步让第二个节点指向第一个（curr）节点，再由curr的前驱指向第二个节点
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy=new ListNode(-1);
        ListNode* pre=dummy;
        dummy->next=head;
        
        for(int i=0;i<m-1;i++)
            pre=pre->next;
        ListNode* cur=pre->next;
        for(int i=m;i<n;i++){
            ListNode* t=cur->next;
            cur->next=t->next;
            t->next=pre->next;
            pre->next=t;
        }
        return dummy->next;
    }
};





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

//前两步记忆后一节点和逆置，后两步移动指针，cur给pre,temp给cur
        ListNode * temp=cur->next;
            cur->next=pre;    //要被赋值的放在左边
            pre=cur;
            cur=temp;

3.递归

递归找到链表尾端，再从尾部一个一个反转，同双指针一样，都会改变链表结构



