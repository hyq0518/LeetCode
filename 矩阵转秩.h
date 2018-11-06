/*
行变列，列变行
*/
vector<vector<int>> transpose(vector<vector<int>>& A) {
	vector<vector<int>>  result;
	for (int i = 0; i < A[0].size(); i++)
	{
		vector<int> temp;
		for (int j = 0; j < A.size(); j++)
			temp.push_back(A[j][i]);
		result.push_back(temp);
	}
	return result;
}