

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        if(prices.size()<=1)                    //  还是清晰表明思路好点  不然容易出问题
        {
            return  0;
            
        }
        int maxpro=0;
        int mini=prices[0];                   //  当prices为空值 注意这种错误  int mini=prices[0];
        for(int i=0;i<prices.size();i++ )
        {
           maxpro=max(maxpro,prices[i]-mini);
            mini=min(mini,prices[i]);
            
        }
        return maxpro;
        
        
        
    }
};
