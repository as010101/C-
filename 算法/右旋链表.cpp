

//找到起点
//对起点之前置空 起点后指向null的指向头
//star 为0或者为链表长度特殊处理
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
    ListNode* rotateRight(ListNode* head, int k) {
        int count=1;
        
        
        if(head==nullptr||head->next==nullptr)
        {
            return head;
        }
        ListNode* end=head,*preEnd=head;
        while(end->next!=nullptr)
        {
            end=end->next;
           count++;
            
        }
        
        int start=count-k%count;
        if(start==0||start==count)          //特殊处理
        {
            return head;
        }
        end=head;
        while(start)
        { 
            preEnd=end;
            end=end->next;
            start--; 
        }
        ListNode* res=end;
        preEnd->next=nullptr;
        while(end->next!=nullptr)
        {
            end=end->next;
        }
        end->next=head;
        return res;
        
    }
};
