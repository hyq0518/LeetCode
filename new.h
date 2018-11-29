/*
归并排序
*/
ListNode * mergeKLists(vector<ListNode*>& lists) {
	if (lists.size() == 0)
		return NULL;
	map<int, int> listmap;
	ListNode *res=NULL,*nt=NULL;
	for (int i = 0; i < lists.size(); i++)
	{
		ListNode* head = lists[i];
		while (head!=NULL)
		{
			listmap[head->val]++;
			head = head->next;
		}
	}
	map<int, int>::iterator iter = listmap.begin();
	while (iter!=listmap.end())
	{
		for (int i = 0; i < (*iter).second; i++)
		{
			ListNode* ln = new ListNode((*iter).first);
			if (res==NULL)
			{
				res = ln;
				nt = res;
			}
			else
			{
				nt->next = ln;
				nt = nt->next;
			}
		}
		iter++;
	}
	return res;
}