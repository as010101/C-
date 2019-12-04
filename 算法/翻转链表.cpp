
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


3.递归



