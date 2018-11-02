/*题目翻译容易产生误解，基本的意思是“R”只能右移，“L”只能向左移*/
bool canTransform(string start, string end) {
	int n=start.size();
	int i=0,j=0;
	//类似字符串交错的思想，找到第一出现的非“X”字符，判断是否满足移动规则。
	while(i<n && j<n){
		while(i<n && start[i]=='X') i++;
		while(j<n && end[j]=='X') j++;
		if(start[i]!=end[j]) return false;
		if((start[i]=='L' && i<j) || (start[i]=='R'&&i>j)) return false;
		i++;
		j++;
	}
	return true;
}
//低效率版本
bool canTransform(string start, string end) {
	if (start.length() != end.length())
	{
		return false;
	}
	int flagR = 0, flagL = 0;
	for (int i = 0; i < start.length(); i++)
	{
		if (start[i] == 'R')
			flagR ++;
		if (end[i] == 'L')
			flagL ++;
		if (flagL > 0 && flagR > 0)
		{
			return false;
		}
		else
		{
			if (flagR == 0 && end[i] == 'R')
				return false;
			if (flagL == 0 && start[i] == 'L')
				return false;
			if (flagR > 0 && end[i] == 'R')
				flagR --;
			if (flagL > 0 && start[i] == 'L')
				flagL --;

		}
		if (i == start.length() - 1)
		{
			if (flagL >0 || flagR >0)
				return false;
		}
	}
	return true;
}
