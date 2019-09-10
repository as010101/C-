class Solution {
public:
    vector<vector<int>>  res;
    vector<vector<int>> levelOrder(TreeNode* root) {

        pre(root,0,res);
         return res;       
    }
    
    void pre(TreeNode * root,int depth,vector<vector<int>> &res )
    {
        
        if(root==nullptr)
        {
            return;
        }
        if(depth>=res.size())
        {
          res.push_back({}) ;       //为什么要这一步，说是扩容，为什么执行这步就能扩容了，res中未见{}
        }
         res[depth].push_back(root->val);   
         pre(root->left,depth+1,res);              //注意这种调用，每次只加入一个节点，而不是两个，注意区分它们的使用时机
        pre(root->right,depth+1,res);
        
    }
