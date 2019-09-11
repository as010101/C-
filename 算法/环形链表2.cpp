class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        
        ListNode * fast=head;
        ListNode * slow=head;
        if(fast==nullptr||fast->next==nullptr)    //此处条件尤其注意fast  if（）；错误写法
        {
            return nullptr;
        }
        fast=fast->next->next;
        slow=slow->next;
        
        while(slow!=fast)
        {
            if(fast==nullptr||fast->next==nullptr)  //跳链尤其要注意访问nullptr指针
            {
                return nullptr;
            }
        fast=fast->next->next;
        slow=slow->next; 
        }
              
        fast=head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;                  
    }
};
