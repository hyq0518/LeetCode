/*
直接翻转，或者保存单词
*/
void reverseWords(string &s) {
	string word = " ";
	string res = "";
	int flag = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != ' ')
		{
			if (flag == 0)
			{
				word += s[i];
				flag = 1;
			}
			else
			{
				word += s[i];
			}
		}
		else
		{
			if (word!=" ")
			{
				res.insert(0,word);
			}
			word = " ";
			flag = 0;
		}
	}
	if (flag!=0)
	{
		res.insert(0, word);
	}
	res.erase(0, 1);
	s = res;
}