
输入: [1,2,3,1]
输出: 4
解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。
示例 2:

输入: [2,7,9,3,1]
输出: 12
解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。



class Solution {
public:
    
    /*
     状态转移方程  f(k) = max(f(k – 2) + n,f（k-1）)    f(k)表示打劫到第k个房子时的最大收益（k= 0...n） 

    */
    
    int rob(vector<int>& nums) {
         int preMax=0;   // f(k-1)
         int ppreMax=0;  // f(k-2)  
        for (int n : nums)
        {
            int temp =preMax;
            preMax=max(ppreMax+n,preMax);
            ppreMax=temp;
        }
        return preMax;
    }
};
