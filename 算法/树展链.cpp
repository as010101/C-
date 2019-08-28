
    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6




class Solution {
public:
    TreeNode * last=nullptr; 
    void flatten(TreeNode* root) {
    
        fun(root);
    }
    void fun(TreeNode * node)
    {   
        if(node==nullptr){return;}
        
        

        
        fun(node->right);                 //要用这种递归方式，以保护右节点信息
        fun(node->left);
         node->right=last;
        node->left=nullptr;
        last=node;                       //要用节点记录链的head 在递归的时候有right可指
    }
    
};
