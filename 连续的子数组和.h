/*
最简单的方法遍历，但是非常慢
更快的的方法，保存所前n项和，
每次迭代为前n项和k的余数，将前n项和的余数保存在一个
unordered_set中，然后每次得出前n项和的余数，在set容器中寻找
是否有
*/
//时间复杂度O(n*n)
bool checkSubarraySum(vector<int>& nums, int k) {
	if (nums.size() == 1)
	{
		return false;
	}
	if (k == 0)
	{
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int sum = nums[i];
			for (int j = i + 1; j < nums.size(); j++)
			{
				sum += nums[j];
				if (sum == 0)
					return true;
			}
		}
		return false;
	}
	for (int i = 0; i < nums.size() - 1; i++)
	{
		int sum = nums[i]%k;
		for (int j = i + 1; j < nums.size(); j++)
		{
			sum += nums[j]%k;
			sum = sum % k;
			if (sum == 0)
				return true;
		}
	}
	return false;
}
//时间复杂度O(n)
bool checkSubarraySum(vector<int>& nums, int k) {
	int n = nums.size();

	vector<int> pres(n + 1, 0);
	for (int i = 1; i < n + 1; ++i) {
		pres[i] = pres[i - 1] + nums[i - 1];
	}
	unordered_set<int> cnt;
	cnt.insert(0);
	//set保存的为前n项和的余数，如果后面余数在set中表示包含连续序列
	for (int i = 2; i < n + 1; ++i) {
		int target = k == 0 ? pres[i] : pres[i] % k;
		//该查找接近于常数的时间复杂度
		if (cnt.find(target) != cnt.end()) {
			return true;
		}
		int val = k == 0 ? pres[i - 1] : pres[i - 1] % k;
		cnt.insert(val);
	}

	return false;
}