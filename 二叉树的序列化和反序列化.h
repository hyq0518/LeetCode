/*

*/
void serializeCore(TreeNode* root, string &s){
	if(root == NULL){
		s += "# ";
		return;
	}
	
	s += to_string(root->val) + " ";
	serializeCore(root->left, s);
	serializeCore(root->right, s);
}

string serialize(TreeNode* root) {
	string s = "";
	serializeCore(root, s);
	s.pop_back();
	return s;
}

// Decodes your encoded data to tree.
TreeNode* deserializeCore(vector<string> &data, int &len, int &n) {
	TreeNode* node = NULL;
	if(data[n] == "#"){//说明这里是null
		return node;
	}
	else{
		node = new TreeNode(stoi(data[n]));
	}
	
	TreeNode* leftnode = NULL, * rightnode = NULL;
	n++;
	if(n <= len - 2){
		leftnode = deserializeCore(data, len, n);
		n++;
		rightnode = deserializeCore(data, len, n);
	}

	node->left = leftnode;
	node->right = rightnode;

	return node;
}

TreeNode* deserialize(string data) {
	if(data == "#" || data == "") return NULL;
	
	int len = 0;
	vector<string> list_s;
	string s = "";
	for(auto d: data){
		if(d == ' '){
			list_s.push_back(s);
			s = "";
			len++;
		}
		else s.push_back(d);
	}
	list_s.push_back(s);
	len++;

	int n = 0;
	TreeNode* root = deserializeCore(list_s, len, n);
	return root;
}



vector<TreeNode*> FindCnode(vector<TreeNode*> childnode)
{
	vector<TreeNode*> result;
	for (int i = 0; i < childnode.size(); i++)
	{
		if (childnode[i] != NULL)
		{
			result.push_back(childnode[i]->left);
			result.push_back(childnode[i]->right);
		}
		else
		{
			result.push_back(NULL);
			result.push_back(NULL);
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] != NULL)
			return result;
	}
	vector<TreeNode*> result1;
	return result1;
}
vector<TreeNode*> CreatCnode(vector<TreeNode*> childnode,vector<string> str,int begin)
{
	vector<TreeNode*> result;
	int val = 0;
	for (int i = 0; i < childnode.size(); i++)
	{
		if (childnode[i] != NULL)
		{
			if (str[begin + 2 * i] != "null")
			{
				istringstream mystream(str[begin + 2 * i]);
				mystream >> val;
				childnode[i]->left = new TreeNode(val);
				result.push_back(childnode[i]->left);
			}
			else
			{
				result.push_back(NULL);
			}
			if (str[begin + 2 * i + 1] != "null")
			{
				istringstream mystream(str[begin + 2 * i + 1]);
				mystream >> val;
				childnode[i]->right = new TreeNode(val);
				result.push_back(childnode[i]->right);
			}
			else
			{
				result.push_back(NULL);
			}
		}
		else
		{
			result.push_back(NULL);
			result.push_back(NULL);
		}
	}
	return result;
}
vector<string> splitStr(string str, char delimiter) {
	vector<string> r;
	string tmpstr;
	while (!str.empty()) {
		int ind = str.find_first_of(delimiter);
		if (ind == -1) {
			r.push_back(str);
			str.clear();
		}
		else {
			r.push_back(str.substr(0, ind));
			str = str.substr(ind + 1, str.size() - ind - 1);
		}
	}
	return r;
}
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
	vector<TreeNode*> childnode;
	string result = "";
	childnode.push_back(root);
	while (childnode.size() != 0)
	{
		for (int i = 0; i < childnode.size(); i++)
		{
			if (childnode[i] != NULL)
			{
				result += to_string(childnode[i]->val) + ',';
			}
			else
			{
				result += "null" + ',';
			}
		}
		childnode = FindCnode(childnode);
	}
	result.erase(result.length() - 1);
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

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
	vector<string> str;
	TreeNode* root;
	str = splitStr(data, ',');
	vector<TreeNode*> childnode;
	int n = 1;
	if (str.size()==0)
		return NULL;
	if (str[0] == "null")
		return NULL;
	istringstream mystring(str[0]);
	mystring >> n;
	root = new TreeNode(n);
	childnode.push_back(root);
	n = 1;
	while (n<str.size())
	{
		childnode = CreatCnode(childnode, str, n);
		n = 2*n + 1;
	}
	return root;
}
	