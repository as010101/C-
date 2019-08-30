




dp[0...n][j]                  当在i的条件下循环完j  则已得到d[i][w]值  即在w的容量下装i个物品的最优
                              对于第i+1个物品，对已有的d[i][0...w]数组的所有值进行遍历,如果有新的值大于原来的d[i][w],更新d[i+1][w]为新的值，否则
                              d[i+1][w]的值就是原来d[i][w]的值
                              对 max(dp[i-1][j], dp[i-1][j-w[i]] + v[i])的解释  (比较的是  没加i物品的最优--- 腾出位置给i，即在j-w[i]容量的容量下的
                              最优d[i-1][j-w[i] 加上v[i]带来的价值)
                              j < w[i] 就是意味着当前i无法更新新的  d[i][j]只能为原值，因为w[i]甚至都放不进去。。。                              


  


int solve(int n, int W) {                //n为数组长度  w为背包容量   w[i] 表示i物品所占背包容量
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {   //i从1开始，因为i=0的值已经确定为0
        for (int j = 0; j <= W; j++) {                 
   
            if (j < w[i]) {         如果j<w[i]   就是
                dp[i][j] = dp[i-1][j];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            }
        }
    }
    return dp[n][W];
}

