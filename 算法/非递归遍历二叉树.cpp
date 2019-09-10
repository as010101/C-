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





//非递归的前序遍历    非递归前序与中序都是一直深入左子树，只是元素推入vector的时机有所不同
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
           vector<int>  res;
        pre(root,res);
        return res;
        
    }
    void pre(TreeNode * node,vector<int> & res)
    {
        if(node==nullptr)
        {
            return;
        }
        TreeNode *p=node;
        stack<TreeNode *> stac;
        while(!stac.empty()||p)
        {
            while(p)
            {
                res.push_back(p->val);
                stac.push(p);
                p=p->left;
                      
            }
            p=stac.top();     //此处留意   
            stac.pop();
            p=p->right;
        }
    }
};
