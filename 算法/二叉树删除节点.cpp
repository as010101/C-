/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  
  
  
    TreeNode* deleteNode(TreeNode* root, int key) {
      
      if(root==nullptr)
      {
        return nullptr;
      }
      
      if(root->val<key)   // 删除节点在右子数中
      {
        root->right=deleteNode(root->right,key);    ///少了root.left
        return  root;////// 
      }
     else if(root->val>key)   // 删除节点在左子数中
      {
       root->left=deleteNode(root->left,key);   
        return  root;////// 
      }
      else      //删除节点为根节点
      {
        
        if(root->left==nullptr){return root->right;}
       else if(root->right==nullptr){return root->left;}
       else{
          TreeNode *nodeMin=min(root->right);
          nodeMin->right=deleteMin(nodeMin->right);         
          nodeMin->left=root->left;
          return nodeMin;
          
        }        
      }
        return nullptr;      
    
    }  
  
   TreeNode * deleteMin(TreeNode * node)     ///删除最小节点
   {
     
     if(node->left==nullptr)
     {
       return node->right;
     }
     node->left=deleteMin(node->left);
     return node;
       
   }
  
  
  
    TreeNode* min(TreeNode * node)              ///找打最小节点
    {
      while(node->left!=nullptr)
      {
        node=node->left;
      }
      return node;
      
    }
  
};
