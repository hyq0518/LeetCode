/*
注意延时
*/
int totalFruit(vector<int>& tree) {
	if (tree.size() == 1)
		return 1;
	int res = 0;
	int fisrt = -1;
	int second = -1;
	for (int i = 0; i < tree.size()-1; i++)
	{
		int fisrt = tree[i];
		int second = -1;
		int sum = 1;
		for (int j = i+1; j < tree.size(); j++)
		{
			if (tree[j] != fisrt&&tree[j]!=second)
			{
				if (second==-1)
				{
					second = tree[j];
					sum++;
				}
				else
				{
					break;
				}
			}
			else
			{
				sum++;
			}

		}
		if (sum > res)
			res = sum;
		if(res>(tree.size()-i))
			break;
	}
	return res;
}