/*
正常做法计数即可，然后把日程安排保存在map中。
*/
class MyCalendarTwo {
public:
	vector<vector<int>> GetCalendar(vector<int> a, vector<int> b)
	{
		vector<vector<int>> result;
		vector<int> temp(2, 0);
		if (b[1]<a[0] || b[0]>a[1])
		{
			return result;
		}
		if (b[0] <= a[0] && b[1] <= a[1])
		{
			temp[0] = a[0] ;
			temp[1] = b[1];
			result.push_back(temp);
			temp[0] = b[0];
			temp[1] = a[0] - 1;
			if (temp[1] < temp[0])
			{
				temp[1] = temp[0] = -1;
			}
			result.push_back(temp);
			temp[0] = b[1]+1;
			temp[1] = a[1];
			if (temp[1] < temp[0])
			{
				temp[1] = temp[0] = -1;
			}
			result.push_back(temp);
			return result;
		}
		if (b[0] >= a[0] && b[1] <= a[1])
		{
			temp[0] = b[0];
			temp[1] = b[1];
			result.push_back(temp);
			temp[0] = a[0];
			temp[1] = b[0]-1;
			if (temp[1] < temp[0])
			{
				temp[1] = temp[0] = -1;
			}
			result.push_back(temp);
			temp[0] = b[1] + 1;
			temp[1] = a[1];
			if (temp[1] < temp[0])
			{
				temp[1] = temp[0] = -1;
			}
			result.push_back(temp);
			return result;
		}
		if (b[0] >= a[0] && b[1] >= a[1])
		{
			temp[0] = b[0];
			temp[1] = a[1];
			result.push_back(temp);
			temp[0] = a[0];
			temp[1] = b[0] - 1;
			if (temp[1] < temp[0])
			{
				temp[1] = temp[0] = -1;
			}
			result.push_back(temp);
			temp[0] = a[1] + 1;
			temp[1] = b[1];
			if (temp[1] < temp[0])
			{
				temp[1] = temp[0] = -1;
			}
			result.push_back(temp);
			return result;
		}
		if (b[0] <= a[0] && b[1] >= a[1])
		{
			temp[0] = a[0];
			temp[1] = a[1];
			result.push_back(temp);
			temp[0] = b[0];
			temp[1] = a[0] - 1;
			if (temp[1] < temp[0])
			{
				temp[1] = temp[0] = -1;
			}
			result.push_back(temp);
			temp[0] = a[1] + 1;
			temp[1] = b[1];
			if (temp[1] < temp[0])
			{
				temp[1] = temp[0] = -1;
			}
			result.push_back(temp);
			return result;
		}
		return result;
	}
	MyCalendarTwo() 
	{

	}
	bool book(int start, int end) 
	{
		vector<int> bookadd(2,0);
		bookadd[0] = start;
		bookadd[1] = end-1;
		if (CalendarOne.size() == 0&& CalendarTwo.size()==0)
		{
			CalendarOne[start] = end -1;
			return true;
		}
		map<int, int>::iterator iter = CalendarTwo.begin();
		while (iter!=CalendarTwo.end())
		{
			vector<vector<int>> result;
			vector<int> bookold(2, 0);
			bookold[0] = (*iter).first;
			bookold[1] = (*iter).second;
			result = GetCalendar(bookadd, bookold);
			if (result.size() != 0)
				return false;
			iter++;
		}
		iter = CalendarOne.begin();
		int flag = -1;
		vector<int> key;
		vector<vector<int>> keyvalue;
		while (iter!=CalendarOne.end())
		{
			vector<vector<int>> result;
			vector<int> bookold(2, 0);
			bookold[0] = (*iter).first;
			bookold[1] = (*iter).second;
			result = GetCalendar(bookadd, bookold);
			if (result.size() == 0 && flag == -1)
			{
				iter++;
				continue;
			}
			if (result.size() == 0 && flag == 0)
			{
				keyvalue.push_back(bookadd);
				flag = 1;
				break;
			}
			if(result.size() != 0)
			{
				key.push_back((*iter).first);
				CalendarTwo[result[0][0]] = result[0][1];
				if (result[1][0] != -1)
					keyvalue.push_back(result[1]);
				if (result[2][0] != -1)
				{
					bookadd[0] = result[2][0];
					bookadd[1] = result[2][1];
				}
				else
				{
					flag = 1;
					break;
				}
				flag = 0;
				iter++;
			}
		}
		if (flag != 1)
		{
			keyvalue.push_back(bookadd);
		}
		for (int i = 0; i < key.size(); i++)
		{
			CalendarOne.erase(key[i]);
		}
		for (int i = 0; i < keyvalue.size(); i++)
		{
			CalendarOne[keyvalue[i][0]]= keyvalue[i][1];
		}
		return true;
	}
private:
	map<int,int> CalendarOne;
	map<int, int> CalendarTwo;
};
class MyCalendarTwo {
public:
    MyCalendarTwo() {
        return;
    }
    
    bool book(int start, int end) {
        vector<pair<int,int>>::iterator it,ins;
        it = MyCal.begin();
        ins = MyCal.begin();
        int e,st,se;
        e = -1;

        for(;it < MyCal.end() && it->first < end;it++)
        {
            if(it->second <= start)
                continue;
            st = max(it->first,start);
                        
            if(st<e)
                return false;
            e = min(it->second,end);
            
            if((it->first < start) )
               ins = it;
        }
        
        for(ins;ins < MyCal.end();ins++)
        {
            if(ins->first > start)
                break;
        }
        
        MyCal.insert(ins,{start,end});
                
        return true;
    }
private:
    vector<pair<int,int>> MyCal;    
};
