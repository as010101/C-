class Solution {
public:
    bool isIsomorphic(string s, string t) {
       unordered_map<char,char> ss,tt;
        for(int i=0;i<s.size();i++)
        {
            ss[s[i]]=t[i];   //充分利用了map的一对一特性，对重复键值重新赋值，将檫除之前的
            tt[t[i]]=s[i];
        }
        
        for(int j=0;j<s.size();j++)
        {
            if(ss[s[j]]!=t[j]||tt[t[j]]!=s[j]) return false;
            
        }
        return true;
    }
};
