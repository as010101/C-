

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"



class Solution {
public:
    int longestValidParentheses(string s) {
        return max( calc(s,'('  ),calc1(s,')'  ));
        
    }
   int  calc( string s,char str)
        
        {
            int max=0;
            int sum=0;
            int validst=0;
            int validlength=0;
            for(int i=0; i<s.size();i++)
            {
              sum+=(s[i]==str ? 1:-1 );
                
                  validst++;
                if(sum<0)
                {
                   max= (max>validlength? max:validlength);
                    sum=0;
                    validst=0;
                }
                else if(sum==0)
                {
                      validlength=validst;
                }
                
                
            }
            
         return  max>validlength? max: validlength;
            
        }
                   
         int  calc1( string s,char str)
        
        {
            int max=0;
            int sum=0;
            int validst=0;
            int validlength=0;
            for(int i=s.size()-1; i>=0;i--)
            {
              sum+=(s[i]==str ? 1:-1 );
                
                validst++;                    //这个变量是关键   如匹配这种（）（），就见效果了
                if(sum<0)
                {
                    max= (max>validlength? max:validlength);                      //max是用来保存之前匹配的最长的有效长度
                    sum=0;
                    validst=0;
                }
                else if(sum==0)
                {
                    
                    validlength=validst;
                    
                    
                }     
            }
            
            return  max>validlength? max: validlength;
            
        }
                   
                   
};
                   
                   
