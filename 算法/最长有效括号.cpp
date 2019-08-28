


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
                   
                   
};
                   
                   
