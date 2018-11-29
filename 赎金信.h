/*
用数组存或者直接map存
*/
bool canConstruct(string ransomNote, string magazine) {
	if (magazine.length()==0)
	{
		if (ransomNote.length() == 0)
			return true;
		else
			return false;
	}
	unordered_map<char, int> mmap;
	for (int i = 0; i < magazine.size(); i++)
	{
		mmap[magazine[i]]++;
	}
	for (int i = 0; i < ransomNote.size(); i++)
	{
		if (mmap[ransomNote[i]]==0)
		{
			return false;
		}
		else
		{
			mmap[ransomNote[i]]--;
		}
	}
	return true;
}