/*
用map存
*/
class Solution {
public:
	Solution(vector<int> nums) {
		for (int i = 0; i < nums.size(); i++)
		{
			pickKey[nums[i]].push_back(i);
		}
	}

	int pick(int target) {
		int wz;
		wz = rand()%pickKey[target].size();
		return pickKey[target][wz];
	}
private:
	unordered_map<int, vector<int>> pickKey;
};