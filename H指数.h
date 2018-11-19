/*
谁小选谁
*/
int hIndex(vector<int>& citations) {
	map<int, int> hmap;
	set<int> hvector;
	for (int i = 0; i < citations.size(); i++)
	{
		hmap[citations[i]] += 1;
	}
	map<int, int>::iterator iter;
	int count = 0;
	iter = hmap.begin();
	while (iter!=hmap.end())
	{
		if ((citations.size()-count)>= (*iter).first)
		{
			hvector.insert((*iter).first);
		}
		else
		{
			hvector.insert(citations.size() - count);
		}
		count += (*iter).second;
		iter++;
	}
	if (hvector.size()==0)
	{
		return 0;
	}
	else
	{
		set<int>::iterator siter;
		siter = hvector.end();
		siter--;
		return *siter;
	}
}