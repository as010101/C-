

输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
输出: [3,3,5,5,6,7] 
解释: 

  滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>  res;
        if(nums.size()<k)
        {
            return nums;
        }

        int j=k-1;
        for(;j<nums.size();j++)
        {
            int i=j-k+1;
            int temp=0;
           int  maxs=nums[j];
             while(i<=j)
             { 
                maxs=max(maxs,nums[i]); 
                 i++;   
             }
              res.push_back(maxs);          
        
        }


        return res;
        
        
    }
};
