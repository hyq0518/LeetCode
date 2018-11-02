/*
找到该数字对应的区间，然后找到该区间的2的幂数，然后判断该数字能否变成该数
判断该数字是否包含2的幂数的所有数字
*/
void findq(int a[],int number)
{
	int x, y;
	x = 1;
	y = 10;
	while (true)
	{
		if (number >= x && number < y)
		{
			a[0] = x;
			a[1] = y;
			break;
		}
		x = x * 10;
		y = y * 10;

	}
	return;
}
void find2m(int a[],int b[])
{
	int x = 1;
	int y = 0;
	while (x<a[1])
	{
		if (x >= a[0] && x < a[1])
		{
			b[y] = x;
			y++;
		}
		x = x * 2;
	}
	return;
}
bool panduan(int N, int L)
{
	string x = to_string(N);
	string y = to_string(L);
	int loc = -1;
	for (int i = 0; i < x.length(); i++)
	{
		loc = y.find(x.at(i), 0);
		if (loc != string::npos)
		{
			y.erase(loc, 1);
		}
		else
		{
			return false;
		}
	}
	return true;
}
bool reorderedPowerOf2(int N) {
	int a[2] = { 0 };
	int b[4] = { 0 };
	this->findq(a, N);
	this->find2m(a, b);
	for (int i = 0; i < 4; i++)
	{
		if (b[i] != 0)
		{
			if (this->panduan(b[i], N))
			{
				return true;
			}
		}
	}
	return false;
}