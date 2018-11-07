/*
核心是动态规划，注意规律是只有两种选择
*/
int rob(vector<int> &nums) {
	int a = 0, b = 0;
	for (int i = 0; i < nums.size(); ++i) {
		int m = a, n = b;
		a = n + nums[i];
		b = max(m, n);
	}
	return max(a, b);
}