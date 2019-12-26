

注意依赖 首先是有了  dp[0][0]  然后在dp[0][j]置初值  然后对dp[1][0]赋初值，如此，依靠初值进行动态路径选择

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(grid.size(),vector<int> (grid[0].size()) );  
         for(int i=0;i<grid.size();i++)
         {
             
           
             for(int j=0;j<grid[0].size();j++)
             {
                
                 
                 if(i==0 && j==0)
                 {
                     dp[i][j]=grid[i][j];
                 }
                else if(i==0)
                 {
                     dp[i][j]=dp[i][j-1]+grid[i][j];    //不是 grid[i][j-1]+grid[i][j]
                 }
                 else if(j==0)
                 {
                     dp[i][j]=dp[i-1][j]+grid[i][j];
                 }
                 else
                 {
                     dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]); //不是 grid[i][j]+min(grid[i-1][j],grid[i][j-1])
                 }
                 
             }
             
         }
        return dp[grid.size()-1][grid[0].size()-1];
        
    }
};
