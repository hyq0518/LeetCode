/*
map保存或者数组保存
*/
bool isAnagram(string s, string t) {
	if (s.length() != t.length())
		return false;
	if (s.length() == 0)
		return true;
	map<char,int> ss;
	map<char,int> ts;
	for (int i = 0; i < s.length(); i++)
	{
		ss[s[i]]++;
		ts[t[i]]++;

	}
	map<char, int>::iterator iter1 = ss.begin();
	map<char, int>::iterator iter2 = ts.begin();
	while (iter1!=ss.end())
	{
		if ((*iter1).first!=(*iter2).first|| (*iter1).second != (*iter2).second)
		{
			return false;
		}
		iter1++;
		iter2++;
	}
	return true;
}