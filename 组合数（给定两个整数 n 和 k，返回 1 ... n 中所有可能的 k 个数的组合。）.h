/*
回溯法，按照组合规则选取即可
*/
vector<vector<int> > combine(int n, int k) {
	vector<vector<int>> result;
	if(n<1||k<0||k>n)
		return result;
	vector<int> path;
	findNum(result,path,n,k,1);
	return result;
}
void findNum(vector<vector<int>>& result,vector<int>& path,int n,int k,int start){
	if(path.size()==k){
		result.push_back(path);
	 //   path.clear();
	}
	for(int i=start;i<=n;i++){
		path.push_back(i);
		findNum(result,path,n,k,i+1);
		path.pop_back();
	}
}