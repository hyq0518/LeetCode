/*
注意顺序
*/
string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
	int add = 0;
	map<int, vector<string>> istmap;
	for (int i = 0; i < indexes.size(); i++)
	{
		istmap[indexes[i]].push_back(sources[i]);
		istmap[indexes[i]].push_back(targets[i]);
	}
	map<int, vector<string>>::iterator myiter = istmap.begin();
	while (myiter!=istmap.end())
	{
		string s1 = S.substr((*myiter).first + add, (*myiter).second[0].length());
		if (s1== (*myiter).second[0])
		{
			S.erase((*myiter).first + add, (*myiter).second[0].length());
			S.insert((*myiter).first + add, (*myiter).second[1]);
			add += (*myiter).second[1].length() - (*myiter).second[0].length();
		}
		myiter++;
	}
	return S;
}