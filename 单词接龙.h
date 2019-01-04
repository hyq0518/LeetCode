/*
BFS，主要注意词列表的索引
*/
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	int step = 1;
	unordered_set<string> wordDict(wordList.begin(), wordList.end());
	if (wordDict.count(endWord) == 0) return 0;
	unordered_set<string> s1{ beginWord };
	unordered_set<string> s2{ endWord };
	while (!s1.empty())
	{
		unordered_set<string> stack;
		for (auto s : s1) wordDict.erase(s);
		for (auto s : s1)
		{
			for (unsigned int i = 0; i < beginWord.size(); ++i)
			{
				for (char c = 'a'; c <= 'z'; ++c)
				{
					string tmp = s;
					tmp[i] = c;
					if (!wordDict.count(tmp)) continue;
					if (s2.count(tmp)) return ++step;
					stack.insert(tmp);
				}
			}
		}
		s1 = stack.size() < s2.size() ? stack : s2;
		s2 = stack.size() < s2.size() ? s2 : stack;
		++step;
	}
	return 0;
}