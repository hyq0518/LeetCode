/*
数组移动
*/
ListNode * rotateRight(ListNode* head, int k) {
	if (head == NULL || head->next == NULL || k == 0)
		return head;
	vector<int> valnum;
	ListNode* lt = head;
	while (lt!=NULL)
	{
		valnum.push_back(lt->val);
		lt = lt->next;
	}
	vector<int> res=valnum;
	for (int i = 0; i < valnum.size(); i++)
	{
		res[(i + k) % valnum.size()] = valnum[i];
	}
	lt = head;
	for (int i = 0; i < res.size(); i++)
	{
		lt->val = res[i];
		lt=lt->next;
	}
	return head;
}