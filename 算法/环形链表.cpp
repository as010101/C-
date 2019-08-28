 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode  *slow=head;
        ListNode  *fast=head;
        while((fast!=nullptr)&&(fast->next!=nullptr))
              {

                  slow=slow->next;    //1
                  fast=fast->next->next;                          注意 1  2顺序不能反了          
                              
                  if(slow==fast)         //2              slow   fast 代表的是节点的地址   不是指针自身的地址
                  {
                      
                      return true;
                  }
              }            
        return  false;
        
    }
};
