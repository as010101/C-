
  // 对出现a*的两种可能分别进行匹配  1 跳过a*直接匹配后面的，因为a*是可匹配可不匹配的，只要后面的匹配为true,就ok,
  如果在递归中出现false,还可进行第二种情况匹配 即 a至少匹配一个，
  这时要求first_match为true, 同时后移s,调用ismatch开始新一轮的匹配       

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s.c_str(), p.c_str());
    }
    
    bool isMatch(const char* s, const char* p) {
        if(*p == 0) return *s == 0;                                //c  的尾标志   返回注意
        
        auto first_match = *s && (*s == *p || *p == '.');        //p的第一个只能为 .或者和s的第一个相同   &&z左边的*s注意
        
        if(*(p+1) == '*'){
            return isMatch(s, p+2) || (first_match && isMatch(++s, p));         //不要忘了first_match
        }
        else{
            return first_match && isMatch(++s, ++p);
        }
    }
};
