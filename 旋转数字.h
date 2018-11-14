/*
遍历
*/
bool isRotated(int n)
{
	if (n == 0)
		return false;
	int flag1 = 0;
	int flag2 = 0;
	while (n>0)
	{
		int md = n % 10;
		if (md == 0 || md == 1 || md == 8)
		{
			flag1++;
			flag2++;
			n = n / 10;
			continue;
		}
		if (md == 2 || md == 5 || md == 6||md==9)
		{
			flag1++;
			flag2+=2;
			n = n / 10;
			continue;
		}
		return false;
	}
	if (flag1 == flag2)
		return false;
	else
		return true;
}
int rotatedDigits(int N) {
	int result = 0;
	for (int i = 0; i <=N; i++)
	{
		if (isRotated(i))
		{
			result++;
		}
	}
	return result;
}