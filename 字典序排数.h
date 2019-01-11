/*
深度优先遍历，dfs与bfs结合
*/
vector<int> lexicalOrder(int n) {
	vector<int> res;
	set<string> zdx;
	while (n>0) zdx.insert(to_string(n--));
	set<string>::iterator iter = zdx.begin();
	while (iter!=zdx.end())
	{
		stringstream out(*iter++);
		out >> n;
		res.push_back(n);
	}
	return res;
}