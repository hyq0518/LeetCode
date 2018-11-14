/*
字符串的插入
*/
string reverseOnlyLetters(string S) {
	map<int,char> FHmap;
	string result="";
	if (S.length()<=1)
	{
		return S;
	}
	for (int i = 0; i < S.length(); i++)
	{
		if ((S[i]<='Z'&&S[i]>='A')|| (S[i] <= 'z'&&S[i] >= 'a'))
		{
			result.insert(result.begin(), S[i]);
		}
		else
		{
			FHmap[i] = S[i];
		}
	}
	map<int, char>::iterator iter;
	iter = FHmap.begin();
	while (iter!=FHmap.end())
	{
		result.insert(result.begin()+(*iter).first, (*iter).second);
		iter++;
	}
	return result;
}