/*
树的广度优先遍历，将每一层的节点存入vector中，迭代获取下一层的节点
*/
//获取每一层的结果，输入当前层的节点，返回下一层的节点
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
//获取二叉数的每一层平均值
vector<double> averageOfLevels(TreeNode* root) {
	vector<double> result;
	vector<TreeNode*> childnode;
	childnode.push_back(root);
	while (childnode.size()!=0)
	{
		double sum = 0.0;
		for (int i=0;i<childnode.size();i++)
		{
			sum += childnode[i]->val;
		}
		result.push_back(sum*1.0 / childnode.size());
		childnode = FindCnode(childnode);
	}
	return result;
}