/*
扩展边缘
*/
vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
	vector<vector<int>> result = M;
	int clen = M.size();
	int klen = M[0].size();
	vector<int> temp;
	for (int i = 0; i < clen; i++)
	{
		for (int j = 0; j < klen; j++)
		{
			M[i][j] += 1;
		}
		M[i].insert(M[i].begin(), 0);
		M[i].push_back(0);
	}
	for (int i = 0; i < M[0].size(); i++)
		temp.push_back(0);
	M.insert(M.begin(), temp);
	M.push_back(temp);
	for (int i = 1; i < M.size() - 1; i++)
	{
		for (int j = 1; j < M[0].size() - 1; j++)
		{
			int sum1 = 0;
			int sum2 = 0;
			for (int n = -1; n< 2; n++)
			{
				for (int m = -1; m < 2; m++)
				{
					sum1 += M[i + n][j + m];
					if (M[i + n][j + m] != 0)
					{
						sum2++;

					}
				}
			}
			result[i - 1][j - 1] = (sum1 - sum2) / sum2;
		}
	}
	return result;
}