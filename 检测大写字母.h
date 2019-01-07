/*
异或，数往右移
*/
bool detectCapitalUse(string word) {
	int num = 0;
	int flag = 0;
	for (int i = 0; i < word.length(); i++)
	{
		if ('Z'-word[i]>=0)
		{
			if (i==0)
			{
				flag = 1;
			}
			num++;
		}
	}
	if (num== word.length()||num==0)
	{
		return true;
	}
	else if(flag==1&&num==1)
	{
		return true;
	}
	else
	{
		return false;
	}
}