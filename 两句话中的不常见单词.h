/*
直接map存，字符串分割
*/
vector<string> splitStr(string str, char delimiter) {
	vector<string> r;
	string tmpstr;
	while (!str.empty()) {
		int ind = str.find_first_of(delimiter);
		if (ind == -1) {
			r.push_back(str);
			str.clear();
		}
		else {
			r.push_back(str.substr(0, ind));
			str = str.substr(ind + 1, str.size() - ind - 1);
		}
	}
	return r;
}
vector<string> uncommonFromSentences(string A, string B) {
	vector<string> res;
	if (A.length()==0&&B.length()==0)
	{
		return res;
	}
	vector<string> vA = splitStr(A,' ');
	vector<string> vB = splitStr(B,' ');
	unordered_map<string, int> AB;
	for (int i = 0; i < vA.size(); i++)
	{
		AB[vA[i]]++;
	}
	for (int i = 0; i < vB.size(); i++)
	{
		AB[vB[i]]++;
	}
	unordered_map<string, int>::iterator iter=AB.begin();
	while (iter!=AB.end())
	{
		if ((*iter).second == 1)
			res.push_back((*iter).first);
		iter++;
	}
	return res;
}