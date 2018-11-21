/*
找到最大最小数，中间序列为2^n个
*/
int sumSubseqWidths(vector<int>& A) {
	sort(A.begin(), A.end());
	int n = A.size();
	vector<long> p(20001,0);
	int temp= 1;
	for (int i=0; i<20001; i++){
		p[i] = temp;
		temp *= 2;
		temp %= 1000000007;
	}
	long res = 0;
	for (int i=0; i<n; i++){
		res += (p[i] - p[n - i - 1]) * A[i];
		res %= 1000000007;
	}
	return res;
}