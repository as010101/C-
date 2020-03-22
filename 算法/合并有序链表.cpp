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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head=new ListNode(0);
        ListNode *p=head;
       //while(l1||l2)  不方便
       while(l1&&l2)
        {
            if(l1->val<l2->val)
            {
                p->next=new ListNode(l1->val);
                l1=l1->next;


            }
            else
            {
               p->next=new ListNode(l2->val);
                l2=l2->next;

            }
            p=p->next;

        }
        if(l1)  p->next=l1;
         if(l2)  p->next=l2;
    
        return head->next;
        
    }
};









//递归，同删除倒数第N个节点有点相似
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL)
        return l2;
    if(l2==NULL)
        return l1;
    if(l1->val < l2->val){
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }else{
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}
