/*
广度优先遍历，将每一层的节点存入vector中
*/
struct TreeLinkNode
{
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution {
public:
//获取下一层的节点
 vector<TreeLinkNode*> FindChild(vector<TreeLinkNode*> nodes)
{
	 vector<TreeLinkNode*> cnodes;
	 for (int i = 0; i < nodes.size(); i++)
	 {
		 if (nodes[i]->left != NULL)
		 {
			 cnodes.push_back(nodes[i]->left);
			 cnodes.push_back(nodes[i]->right);
		 }
		 else
		 {
			 return cnodes;
		 }
	 }
	 return cnodes;
}
//产生一颗满二叉树
 void CreatTree(TreeLinkNode* root,int depth)
 {
	 if (depth == 0)
	 {
		 return;
	 }
	 else
	 {
		 root->left = new TreeLinkNode(root->val * 2);
		 root->right = new TreeLinkNode(root->val * 2 + 1);
		 CreatTree(root->left, depth - 1);
		 CreatTree(root->right, depth - 1);
	 }
 }
 //完成操作
void connect(TreeLinkNode *root) {
	if (root == NULL)
	{
		return;
	}
	vector<TreeLinkNode*> nodes;
	nodes.push_back(root);
	while(true)
	{
		nodes = FindChild(nodes);
		if (nodes.size() == 0)
		{
			break;
		}
		else
		{
			for (int i = 0; i < nodes.size(); i++)
			{
				if (i < nodes.size() - 1)
				{
					nodes[i]->next = nodes[i + 1];
				}
				else
				{
					nodes[i]->next = NULL;
				}
			}
		}
	}

}
};
