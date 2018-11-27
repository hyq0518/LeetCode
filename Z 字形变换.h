/*
两个转向标志
*/
string convert(string s, int numRows) {
	if (numRows<=1)
	{
		return s;
	}
	vector<string> res(numRows);
	string result = "";
	int count = 0;
	bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (count == numRows)
		{
			flag=!flag;
			count = numRows - 2;
		}
		if (count == 0)
		{
			flag = !flag;
		}
		if (flag)
		{
			res[count] += s[i];
			count++;
		}
		else
		{
			res[count] += s[i];
			count--;
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		result += res[i];
	}
	return result;
}