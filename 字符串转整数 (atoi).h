/*
��Ҫע�������ط���ȥ�ո�Ϊȥ���ַ�ǰ�ո�Ҫ�����ڵ���ȥ��
*/
int myAtoi(string str) {
	if (str.length() == 0)
		return 0;
	string::iterator it = str.begin();
	//ȥ�ո�
	while (it != str.end())
	{
		if (*it == ' ')
			str.erase(it);
		else
		{
			break;
		}
	}
	string nums;
	int result = 0;
	int flag = 0;
	//��ȡ����
	if (str[0] == '-' || str[0] == '+' || (str[0] >= '0'&&str[0] <= '9'))
	{
		if (str[0] == '-')
		{
			flag = -1;
			str.erase(str.begin());
		}
		else if (str[0] == '+')
		{
			flag = 1;
			str.erase(str.begin());
		}
		if (flag == 0)
			flag = 1;
		if (str[0] >= '0'&&str[0] <= '9')
		{
			int i = 0;
			while (str[i] >= '0'&&str[i] <= '9')
			{
				nums += str[i];
				i++;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
	long long num = 0;
	//while (nums[0]=='0'&&nums.length()>1)
	//{
	//	nums.erase(nums.begin());
	//}
	//���ַ���ת��Ϊlong long�ͣ����߲����ı������ж�
	//����תlong long
	istringstream myin(nums);
	if (nums.length() > 12)
		nums = nums.substr(0, 12);
	myin >> num;
	if (num*flag>INT_MAX)
	{
		result = INT_MAX;
	}
	else if (num*flag<INT_MIN)
	{
		result = INT_MIN;
	}
	else
	{
		result = num * flag;
	}
	return result;
}