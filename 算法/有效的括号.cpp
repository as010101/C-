class Solution {
public:
    int i=0;
    stack<char> st;
    bool isValid(string s) {
        while(i<s.size())
      {
            
         if(st.empty()){st.push(s[i]);}
        else if( s[i]==')')
        {
            char temp=st.top();
          if(temp!='(')        {return false;}
            st.pop();
            
        }
         else    if(s[i]==']')
        {
                            char temp=st.top();
          if(temp!='[')    {return false;}
            st.pop();    
        }
        else if (s[i]=='}')
        {
          char temp=st.top();
          if(temp!='{')  {return false;}
         st.pop();     
        }
        else
        {
            st.push(s[i]);   
        }
              i++;      
     }       
       if(!st.empty())
       {
        return false;
       }
        else{return true;};
    }
};
