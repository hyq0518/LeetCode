/*
异或，数往右移
*/
vector<vector<int>> threeSum(vector<int>& nums) {
	int i = 0, j, k;
	vector<vector<int> > result;
	if (nums.size() < 3)
		return result;
	sort(nums.begin(), nums.end());
	while(i < nums.size() - 2 && nums[i] <= 0)
	{
		j = i + 1;
		k = nums.size() - 1;
		while (j < k)
		{
			if (nums[j] + nums[k] == -nums[i])
			{
				vector<int> vecTemp = {nums[i], nums[j], nums[k]};
				result.push_back(vecTemp);
				while(nums[j] == nums[--j]){}
				while(nums[k] == nums[--k]){}
			}
			else if (nums[j] + nums[k] > -nums[i])
				k--;
			else
				j++;
		}
		while(nums[i] == nums[++i]) {}
	}
	return result;
}
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> res;
	if (nums.size() <= 2)
	{
		return res;
	}
	sort(nums.begin(), nums.end());
	for (int i = 0; i < nums.size() - 2; i++)
	{
		if (nums[i] + nums[nums.size() - 2] + nums[nums.size() - 1]<0 || (i>0 && nums[i] == nums[i - 1]))
		{
			continue;
		}
		for (int j = i + 1; j < nums.size() - 1; j++)
		{
			if (nums[i] + nums[j] + nums[nums.size() - 1]<0 || (nums[j - 1] == nums[j] && j - 1>i))
			{
				continue;
			}
			int result = binarySearch2(nums, j + 1, nums.size() - 1, -(nums[i] + nums[j]));
			if (result != -1)
			{
				vector<int> nv;
				nv.push_back(nums[i]);
				nv.push_back(nums[j]);
				nv.push_back(-(nums[i] + nums[j]));
				res.push_back(nv);
			}
			if (nums[i] + nums[j]>0)
			{
				break;
			}
		}
		if (nums[i]>0)
		{
			break;
		}
	}
	return res;
}