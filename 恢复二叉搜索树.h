/*
中缀式
*/
class Solution {
public:
	void FindErro(TreeNode* root)
	{
		if (flag == 2)
			return;
		if (root->left != NULL)
			FindErro(root->left);
		if (last != NULL)
		{
			if (last->val>root->val&&flag == 1)
			{
				second = root;
				flag = 2;
			}
			if (last->val>root->val&&flag == 0)
			{
				first = last;
				second = root;
				flag = 1;
			}
		}
		last = root;
		if (root->right != NULL)
			FindErro(root->right);
		return;
	}
	void recoverTree(TreeNode* root) {
		flag = 0;
		FindErro(root);
		int value = 0;
		value = first->val;
		first->val = second->val;
		second->val = value;
	}
private:
	TreeNode * first, *second, *last;
	int flag = 0;
};