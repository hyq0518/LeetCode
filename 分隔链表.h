/*
大于x和小于x的vector
*/
ListNode * partition(ListNode* head, int x) {
	if (head == NULL)
	{
		return NULL;
	}
	vector<int> bigv;
	vector<int> smallv;
	ListNode* nt = head;
	ListNode* res = NULL;
	while (nt != NULL)
	{
		if (nt->val >= x)
			bigv.push_back(nt->val);
		else
			smallv.push_back(nt->val);
		nt = nt->next;
	}
	for (int i = bigv.size() - 1; i >= 0; i--)
	{
		if (res == NULL)
		{
			res = new ListNode(bigv[i]);
		}
		else
		{
			ListNode* temp = new ListNode(bigv[i]);
			temp->next = res;
			res = temp;
		}
	}
	for (int i = smallv.size() - 1; i >= 0; i--)
	{
		ListNode* temp = new ListNode(smallv[i]);
		temp->next = res;
		res = temp;
	}
	return res;
}