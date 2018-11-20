/*
大数相加，字符串相加
*/
string stradd(string num1, string num2) //num1<=num2
{
	int num1int = 0, num2int = 0, res = 0;
	string resstr = "";
	for (int i = 0; i < num1.length(); i++)
	{
		num1int = num1[num1.length() - 1 - i] - '0';
		num2int = num2[num2.length() - 1 - i] - '0';
		resstr.insert(resstr.begin(), (num1int + num2int + res) % 10 + '0');
		res = (num1int + num2int + res) / 10;
	}
	for (int i = 0; i < num2.length() - num1.length(); i++)
	{
		num2int = num2[num2.length() - num1.length() - 1 - i] - '0';
		resstr.insert(resstr.begin(), (num2int + res) % 10 + '0');
		res = (num2int + res) / 10;
	}
	if (res != 0)
		resstr.insert(resstr.begin(), res + '0');
	return resstr;
}
ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	string num1="";
	string num2="";
	ListNode* temp = l1;
	while (temp!=NULL)
	{
		num1 += to_string(temp->val);
		temp = temp->next;
	}
	temp = l2;
	while (temp != NULL)
	{
		num2 += to_string(temp->val);
		temp = temp->next;
	}
	string resstr = "";
	if (num1.length() <= num2.length())
	{
		resstr = stradd(num1, num2);
	}
	else
	{
		resstr = stradd(num2, num1);
	}
	int str2int = resstr[0] - '0';
	ListNode* result = new ListNode(str2int);
	ListNode* end =result;
	for (int i = 1; i < resstr.length(); i++)
	{
		int str2int = resstr[i] - '0';
		ListNode* temp = new ListNode(str2int);
		end->next = temp;
		end = temp;
	}
	return result;
}