/*
核心是n二进制不连续性1的数量是一个斐波那契数列，然后逐步累加即可。
*/
int findIntegers(int num) {
	int res = 0;
	int fb[31] = { 0 };
	fb[0] = 1;
	fb[1] = 2;
	for (int i = 2; i < 30; i++)
	{
		fb[i] = fb[i - 1] + fb[i - 2];
	}
	vector<int> one;
	int ip = 1;
	while (num!=0)
	{
		if (num%2==1)
		{
			one.push_back(ip);
		}
		num = num / 2;
		ip++;
	}
	if (one.size() == 1)
		return fb[one[0]-1] + fb[0];
	res = fb[one[one.size() - 1] - 1];
	for (int i = one.size()-2; i >=0; i--)
	{
		if (one[i + 1] - one[i] == 1)
			return res + fb[one[i] - 1];
		else
			res += fb[one[i] - 1];
	}
	return res + fb[0];
}