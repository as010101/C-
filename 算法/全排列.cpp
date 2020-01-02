class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> res;
        vector<bool> flag(nums.size(),false);//标记元素是否被访问过
        return HDFS(results,res,flag,nums,0);
    }
    vector<vector<int>> HDFS(vector<vector<int>> &results,vector<int> &res,vector<bool> &flag,vector<int> nums,int dep){
        if(dep==nums.size()){//达到树叶
            results.push_back(res);
        }
        for(int i=0;i<nums.size();i++){//每层都对每个节点进行检测
            if(!flag[i]){
                flag[i]=true;//访问节点
                res.push_back(nums[i]);
                HDFS(results,res,flag,nums,dep+1);  //进入下一层
                res.pop_back();//往上一层回退
                flag[i]=false;
            }
        }
        return results;
    }
};
















class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
    
        vector<bool> visit(nums.size(),false);
        vector<vector<int>> vec;
        vector<int >  dfsv;
        HDFS(vec,dfsv,nums,visit);
        return vec;
    }
    
    void HDFS( vector<vector<int>>  & vec,vector<int> & dfsv,vector<int> & nums, vector<bool> &visit)
    {
        if(dfsv.size()>=nums.size())
        {
            vec.push_back(dfsv);
           
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(!visit[i])
            {
                dfsv.push_back(nums[i]);
                visit[i]=true;
                HDFS(vec,dfsv,nums,visit);
                dfsv.pop_back();                //注意此处的回弹，写的时候漏掉了  
                 visit[i]=false;    
            }
            
            
        }
        
        
        
    }
};
