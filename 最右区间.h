/*
二分查找
*/
vector<int> findRightInterval(vector<Interval>& intervals) {
	int n=intervals.size();
	unordered_map<int,int> m;
	vector<int> vec(n,0),res(n,-1);
	for(int i=0;i<n;i++){
		int tmp=intervals[i].start;
		vec[i]=intervals[i].start;
		m[tmp]=i;
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<n;i++){
		int end=intervals[i].end;
		auto it=lower_bound(vec.begin(),vec.end(),end);
		if(it!=vec.end()) res[i]=m[*it]; 
	}
	return res;
}