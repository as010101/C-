class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>  dp(s.size()+1,false);  //为什么要+1   因为string 的substr从1开始
        unordered_set<string>  dic(wordDict.begin(),wordDict.end());                            //map
        dp[0]=true;
        for(int i=1;i<=s.size();i++)
        {     
            for(int j=0;j<=i;j++)
            {
                if(dp[j]&&dic.find(s.substr(j,i-j))!=dic.end()) //思路就是s的前i个已经满足时，加入第i+1个字符串时，对整个长
                {                                              //为i+1的字符串进行匹配，如果只要满足两种情况中的一种
                                                                //便可将dp[i]=true,  1 s[0..i+1]在dic中被找到 
                                                                 //                 2  s[j..i+1]在dic中被找到，s[0..j-1]
                                                                //                                  是之前已经被满足了的
                    dp[i]=true;    //此处是dp[i] 不是dp[j]
                   break;
                }     
            }
        }
        return dp[s.size()];
    }
};
