
TreeNode *  treeCreateSub(int num,TreeNode * root)
{
	if (root == nullptr)
	{
		root - >val = num;
	}
	else  if(root->val<sum)
	{
		if (root->left == nullptr)
		{
			TreeNode* node = new TreeNode;
			node->val = num;
			root->left = node;
		}
		else
		{
			treeCreateSub(num, root->left);
		}
	}
	else 
	{
		if (root->left == nullptr)
		{
			TreeNode* node = new TreeNode;
			node->val = num;
			root->right = node;
		}
		else
		{
			treeCreateSub(num, root->right);
		}
	
	}
}
