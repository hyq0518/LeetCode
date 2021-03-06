/*
树的广度优先遍历，将每一层的节点保存在vector中
*/
//寻找下一层节点
vector<TreeNode*> FindCnode(vector<TreeNode*> childnode)
{
	vector<TreeNode*> result;
	for (int i = 0; i < childnode.size(); i++)
	{
		if (childnode[i]->left != NULL)
		{
			result.push_back(childnode[i]->left);
		}
		if (childnode[i]->right != NULL)
		{
			result.push_back(childnode[i]->right);
		}
	}
	return result;
}
//返回左下角值
int findBottomLeftValue(TreeNode* root) {
	vector<TreeNode*> childnode;
	childnode.push_back(root);
	int result = 0;
	while (childnode.size()!=0)
	{
		result = childnode[0]->val;
		childnode = FindCnode(childnode);			
	}
	return result;
}
void CreatTree(TreeNode* root, int depth)
{
	if (depth == 0)
	{
		return;
	}
	else
	{
		root->left = new TreeNode(root->val * 2);
		root->right = new TreeNode(root->val * 2 + 1);
		CreatTree(root->left, depth - 1);
		CreatTree(root->right, depth - 1);
	}
}