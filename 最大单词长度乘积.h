/*
通过&运算来比较两个字符串是否有相同部分，将字符串转化为二进制串
*/
int maxProduct(vector<string>& words) {
	int Len = words.size();
	vector<int> Hash(Len, 0);
	for (int i = 0; i < Len;i++) {
		for (int j = 0; j < words[i].size(); j++) {
			Hash[i] |= 1 << (words[i][j] - 'a');
		}
	}

	int Res = 0;
	for (int i = 0; i < Len; i++) {
		for (int j = i + 1; j < Len; j++) {
			if ((Hash[i] & Hash[j]) == 0) {
				int T = words[i].size()*words[j].size();
				Res = max(Res, T);
			}
		}
	}
	return Res;
}
bool WordsCompare(string str1, string str2)
{
	if (str1.length() < str2.length())
	{
		for (int i = 0; i < str1.length(); i++)
		{
			if (str2.find(str1[i]) != string::npos)
			{
				return false;
			}
		}
	}
	else
	{
		for (int i = 0; i < str2.length(); i++)
		{
			if (str1.find(str2[i]) != string::npos)
			{
				return false;
			}
		}
	}
	return true;
}
int maxProduct(vector<string>& words) {
	set<int> wordset;
	for (int i = 0; i <words.size()-1; i++)
	{
		for (int j = i+1; j<words.size(); j++)
		{
			if (WordsCompare(words[i], words[j]))
			{
				wordset.insert(words[i].length()*words[j].length());
			}
		}
	}
	set<int>::iterator iter = wordset.end();
	if (wordset.size() == 0)
	{
		return 0;
	}
	else
	{
		iter--;
		return *iter;
	}
}