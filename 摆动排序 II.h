/*
排序。。。
*/
void wiggleSort(vector<int>& nums) {
	vector<int> res;
	sort(nums.begin(), nums.end());
	vector<int> bg(nums.begin(), nums.begin() + ceil(nums.size() / 2.0));
	vector<int> ed(nums.begin() + ceil(nums.size() / 2.0), nums.end());
	for (int i = 0; i < bg.size(); i++)
	{
		res.push_back(bg[bg.size()-1-i]);
		if (i < ed.size()) res.push_back(ed[ed.size() - 1 - i]);
	}
	nums = res;
}