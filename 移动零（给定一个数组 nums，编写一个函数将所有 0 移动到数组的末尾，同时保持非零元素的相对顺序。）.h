/*
vector的删除和添加操作
*/
void moveZeroes(vector<int>& nums) {
	if (nums.size() == 0)
	{
		return;
	}
	int i = 0;
	int count=0;
	while (true)
	{
		if (count == nums.size())
		{
			return;
		}
		if (nums[i] == 0)
		{
			nums.erase(nums.begin() + i);
			nums.push_back(0);
			i--;
		}
		i++;
		count++;
	}
}