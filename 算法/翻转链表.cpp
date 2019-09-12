
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
