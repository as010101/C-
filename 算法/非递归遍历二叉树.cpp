class Solution {
public:
   vector<int>  vec;
    vector<int> inorderTraversal(TreeNode* root) {
        
        if(root==nullptr)
        {   
            return  vec;
        }

        stack<TreeNode*> stac;
        TreeNode * p=root;
        while(!stac.empty()||p)                    //注意是两层while循环
        {
        while(p)                   //注意循环的条件是p  此处是最关键的
        {
        stac.push(p);                          //stac记录好每个左孩子的分支节点
        p=p->left;            
        }

        p=stac.top();
        stac.pop();
        vec.push_back(p->val);
        p=p->right;                        

        
        }
        
        return vec;
    }
};
