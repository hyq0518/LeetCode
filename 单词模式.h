/*
字符串的分割
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
bool wordPattern(string pattern, string str) {
	vector<string> words;
	words = splitStr(str, ' ');
	map<char, string> wordsmap;
	map<string, char> wordmap;
	if (pattern.length() != words.size())
		return false;
	for (int i = 0; i < pattern.length(); i++)
	{
		if (wordsmap[pattern[i]] == "\0"&&wordmap[words[i]]=='\0')
		{
			wordsmap[pattern[i]] = words[i];
			wordmap[words[i]] = pattern[i];
		}
		else if(wordsmap[pattern[i]]!= words[i])
		{
			return false;
		}
	}
	return true;
}