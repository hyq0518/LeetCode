/*
加入随机
*/
int hammingDistance(int x, int y) {
vector<string> finddifference(vector<string> wordlist, int num, string word)
{
	vector<string> res;
	for (int i = 0; i < wordlist.size(); i++)
	{
		int sum = 0;
		for (int j = 0; j < word.length(); j++)
		{
			if (wordlist[i][j] != word[j])
			{
				sum++;
			}
		}
		if (sum == num)
		{
			res.push_back(wordlist[i]);
		}
	}
	return res;
}
void findSecretWord(vector<string>& wordlist, Master& master) {
	int samenum = 0;
	vector<string> newordlist = wordlist;
	int guess = 0;
	while (samenum != 6 && guess < 10)
	{
		int x=rand()%newordlist.size();
		samenum = master.guess(newordlist[x]);
		newordlist = finddifference(newordlist, 6 - samenum, newordlist[x]);
		guess++;
	}
}