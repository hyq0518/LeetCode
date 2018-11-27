/*
判断一个图是否为二分图
*/
bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
	int first,second;
	vector<int>color(N+1,-1);
	 vector<vector<int> >adj(N+1);
	for(int i=0;i<dislikes.size();i++)
	{
		first=dislikes[i][0];
		second=dislikes[i][1];
		adj[first].push_back(second);
		adj[second].push_back(first); }
		for(int i=1;i<=N;i++)
			if(color[i]==-1&&!dfs(adj,i,color,1))return false;
   
	return true;
}
bool dfs( vector<vector<int> >&adj,int n,vector<int>&color,int C)
{
	if(color[n]!=-1)
	{
		return color[n]==C;
	}
	color[n]=C;
	for(int next:adj[n])
	{
		if(!dfs(adj,next,color,1-C))return false;
	}
	return true;
}