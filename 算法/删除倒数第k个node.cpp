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
int count=0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr)return nullptr;
        head->next=removeNthFromEnd(head->next,n);
            count ++;
        if(n==count)
        {
            return head->next;
        }
       // count ++;   不能是在这儿++;
        return head;
        
    }

 
};
