/*
先取得牌照中的所有字母，然后逐个排查是否包含牌照字母
*/
string shortestCompletingWord(string licensePlate, vector<string>& words) {
	string::iterator t = licensePlate.begin();
	while (t!=licensePlate.end())
	{
		if ((*t >= '0'&&*t <= '9')||*t==' ')
		{
			licensePlate.erase(t);
		}
		else
		{
			t++;
		}
	}
	transform(licensePlate.begin(),licensePlate.end(),licensePlate.begin(), ::tolower);
	vector<string> cwords;
	vector<string> fhwords;
	cwords = words;
	fhwords = words;
	t = licensePlate.begin();
	while (t != licensePlate.end())
	{
		if (cwords.size() != 0)
		{
			for (int i = 0; i < cwords.size(); i++)
			{
				int pos;
				pos = cwords[i].find(*t);
				if (pos != string::npos)
				{
					cwords[i].erase(cwords[i].begin() + pos);
				}
				else
				{
					cwords.erase(cwords.begin() + i);
					fhwords.erase(fhwords.begin() + i);
					i--;
				}
			}
		}
		t++;
	}
	int len=9999;
	string str;
	for (int i = 0; i < fhwords.size(); i++)
	{
		if (fhwords[i].length() < len)
		{
			str = fhwords[i];
			len = fhwords[i].length();
		}
	}
	return str;
}