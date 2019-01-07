/*
记录奇数和偶数的位置
*/
vector<int> sortArrayByParityII(vector<int>& A) {
	vector<int> res(A.size());
	int jswz = 1;
	int oswz = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i]%2==0)
		{
			res[oswz] = A[i];
			oswz = oswz + 2;
		}
		else
		{
			res[jswz] = A[i];
			jswz = jswz + 2;
		}
	}
	return res;
}