
//递归的核心  想象一下各种可能情况下，返回的头是不是都是已存在的值，如此种情况，这儿只能是 first or second Node
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // if(head->next==nullptr||head->next==nullptr)
        // {
        //     return head;
        // }
        if(head==NULL||head->next==NULL)   //处理奇数链表的正确做法
        return head;
        ListNode *second=head->next;
        ListNode *third=second->next;
        head->next=swapPairs(third);
        second->next=head;
        return second;

        
    }
};
