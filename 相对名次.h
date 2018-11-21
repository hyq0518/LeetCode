/*
直接排名即可
*/
vector<string> findRelativeRanks(vector<int>& nums) {
	map<int, vector<int>> score;
	vector<string> result(nums.size());
	for (int i = 0; i < nums.size(); i++)
	{
		score[nums[i]].push_back(i);
	}
	int count = 1;
	map<int, vector<int>>::iterator iter = score.end();
	iter--;
	while (true)
	{
		for (int i = 0; i < (*iter).second.size(); i++)
		{
			if (count <= 3)
			{
				if (count == 1)
				{
					result[(*iter).second[i]] = "Gold Medal";
				}
				if (count == 2)
				{
					result[(*iter).second[i]] = "Silver Medal";
				}
				if (count == 3)
				{
					result[(*iter).second[i]] = "Bronze Medal";
				}
			}
			else
			{
				result[(*iter).second[i]] = to_string(count);
			}
		}
		count += (*iter).second.size();
		if (iter == score.begin())
			break;
		iter--;
	}
	return result;
}