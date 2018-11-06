/*
主要是减少时间复杂度，直接把复杂度降为O(n*n)
直接通过map计算即可
*/
int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
	int result = 0;
	unordered_map<int, int> mAB;
	unordered_map<int, int> mCD;
	for (int i = 0; i < A.size(); i++)
	{
		for (int j = 0; j < B.size(); j++)
		{
			mAB[A[i] + B[j]] += 1;
			mCD[C[i] + D[j]] += 1;
		}
	}
	unordered_map<int, int>::iterator mit;
	mit = mAB.begin();
	while (mit!=mAB.end())
	{
		if(mCD.find(0 - (*mit).first)!=mCD.end())
			result += (*mit).second * mCD[0 - (*mit).first];
		mit++;
	}
	return result;
}