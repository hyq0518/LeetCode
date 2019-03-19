/*
选取一个点作为山顶，判断上的长度，长度小于3的不是山
理论时间复杂度为O（n），每次选择上次的右山脚旁边点作为
山顶遍历，另一种思路dp与字符串中最长回文序列一样
*/
int longestMountain(vector<int>& A) {
	if (A.size() == 0)
		return 0;
	int res = 0;
	int left = 0;
	int right = 0;
	//选取山顶
	for (int i = 1; i < A.size(); i=right+1) {
		left = i - 1;
		right = i + 1;
		while (left >= 0 && A[left] < A[left + 1])
			left--;
		left++;
		while (right < A.size() && A[right] < A[right - 1])
			right++;
		right--;
		//判断山的长度
		if (right - left + 1 >= 3&&left!=i&&right!=i) {
			if (right - left +1> res)
				res = right - left + 1;
		}
	}
	return res;
}