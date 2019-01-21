/*
二进制思想
*/
vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res(1);
	if (nums.size()==0)
	{
		return res;
	}
	int n = pow(2,nums.size())-1;
	while (n>0)
	{
		vector<int> temp;
		int t = n;
		int ct = 0;
		while (t!=0)
		{
			if (t%2==1)
			{
				temp.push_back(nums[ct]);
			}
			t = t / 2;
			ct++;
		}
		res.push_back(temp);
		n--;
	}
	return res;
}