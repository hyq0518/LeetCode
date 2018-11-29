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
ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    	if(lists.size()==0){
    		return NULL;
		}
		if(lists.size()==1){
			return lists[0];
		}
		if(lists.size()==2){
			return mergeTwoLists(lists[0],lists[1]);
		}
    	
    	ListNode* left=NULL;
    	ListNode* right=NULL;
    	std::vector<ListNode*>left_vec;
    	std::vector<ListNode*>right_vec;
    	
    	int mid=lists.size()/2;
    	
    	for(int i=0;i < mid;i++){
    		left_vec.push_back(lists[i]);
		}
		left=mergeKLists(left_vec);
		
		for(int i=mid; i < lists.size();i++){
			right_vec.push_back(lists[i]);
		}
		right=mergeKLists(right_vec);
		
		ListNode* head=mergeTwoLists(left,right);
		
		return head;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode new_node(0);
        ListNode* ptr= &new_node;
        
        while(l1 && l2){
        	if(l1->val < l2->val){
        		ptr->next=l1;
        		l1=l1->next;
			}else{
				ptr->next=l2;
				l2=l2->next;
			}
			ptr=ptr->next;
		}
		
		if(l1){
			ptr->next=l1;
		}
		if(l2){
			ptr->next=l2;
		}
		return new_node.next;
    }