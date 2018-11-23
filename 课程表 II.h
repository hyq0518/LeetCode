/*
有向图的拓扑排序，取入度为零的节点，然后不断插入
*/
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
	map<int, int> indegree;
	vector<int> rykc;
	map<int, vector<int>> degreein;
	map<int, vector<int>> before;
	vector<int> result;
	//初始化入度map和关系map
	for (int i = 0; i < prerequisites.size(); i++)
	{
		indegree[prerequisites[i].first] += 0;
		indegree[prerequisites[i].second] += 1;
		before[prerequisites[i].first].push_back(prerequisites[i].second);
	}
	if (indegree.size()!= numCourses)
	{
		for (int i = 0; i < numCourses; i++)
		{
			if (indegree.find(i) == indegree.end())
				rykc.push_back(i);
		}
	}
	map<int, int>::iterator iter = indegree.begin();
	while (iter!=indegree.end())
	{
		degreein[(*iter).second].push_back((*iter).first);
		iter++;
	}
	if (degreein.size() != 0)
	{
		while (degreein[0].size() != 0)
		{
			int kc = (*degreein.begin()).second[0];
			result.insert(result.begin(),kc);
			(*degreein.begin()).second.erase((*degreein.begin()).second.begin());
			for (int i = 0; i < before[kc].size(); i++)
			{
				int wz = 0;
				for (int j = 0; j < degreein[indegree[before[kc][i]]].size(); j++)
				{
					if (degreein[indegree[before[kc][i]]][j] == before[kc][i])
					{
						wz = j;
						break;
					}
				}
				degreein[indegree[before[kc][i]]].erase(degreein[indegree[before[kc][i]]].begin() + wz);
				degreein[indegree[before[kc][i]] - 1].push_back(before[kc][i]);
				indegree[before[kc][i]]--;
			}
		}
	}
	for (int i = 0; i < rykc.size(); i++)
	{
		result.push_back(rykc[i]);
	}
	if (result.size()!=numCourses)
	{
		vector<int> res;
		return res;
	}
	else
	{
		return result;
	}
}
 vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

	vector<int> out;
	vector<int>cd(numCourses,0);
	vector<vector<int>> rd(numCourses);
	for(auto p:prerequisites)
	{
		auto f=p.first;
		auto s=p.second;
		cd[f]++;
		rd[s].push_back(f);
	}
	queue<int>dp;
	for(int i=0;i<numCourses;i++)
	{
		if(cd[i]==0)
		{
			out.push_back(i);
			dp.push(i);
		}
	}
	while(!dp.empty())
	{
		int len=dp.size();
		while(len--)
		{
			auto f=dp.front();
			for(int j=0;j<rd[f].size();j++)
			{
				int t=rd[f][j];
				cd[t]--;
				if(cd[t]==0){
					  out.push_back(t);
					dp.push(t);}
			}
			dp.pop();
		}
	}
	if(accumulate(cd.begin(),cd.end(),0)!=0)
		return vector<int>();
	return out;
}