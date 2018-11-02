//关键是块注释，一个语句中可能会出现多个块注释，行注释处理较为简单。
//块注释注意匹配（"/*/"是一个小问题），删除块注释后应该重新处理该行
vector<string> removeComments(vector<string>& source) {
	vector<string> result;
	vector<string> zresult;
	if (source.size() == 0)
		return source;
	int flag = 0;
	int flag2 = 0;
	zresult = source;
	for (int i = 0; i < source.size(); i++)
	{
		int hzs = 0;
		int dzs = 0;
		int dzse = 0;
		if (flag == 0)//块注释标识，表示块注释的标识“/*”不在当前行
		{
			hzs = zresult[i].find("//");
			dzs = zresult[i].find("/*");
			if (hzs == -1)//未找到行注释
			{
				hzs = zresult[i].length() + 1;
			}
			if (dzs == -1)//未找到块注释
			{
				dzs = zresult[i].length() + 1;
			}
			if (hzs != dzs)//该行是否有注释
			{
				if (hzs < dzs)//行注释在块注释前面，块注释无效
				{
					string str;
					str = zresult[i].replace(zresult[i].begin() + hzs, zresult[i].end(), "");
					if (flag2 == 1)//该行是否之前清除了块注释
					{
						if (result.size() != 0)
						{
							result[result.size() - 1] += str;
						}
						else
						{
							if (str != "")
							{
								result.push_back(str);
							}
						}
						flag2 = 0;
					}
					else
					{
						if (str != "")
						{
							result.push_back(str);
						}
					}
				}
				else
				{
					string strr;
					string str;
					zresult[i].replace(zresult[i].begin() + dzs, zresult[i].begin() + dzs + 2, "?");//防止出现“/*/”
					//防止出现“*/”在“/*”前面的情况
					strr = zresult[i].substr(dzs, zresult[i].length());
					dzse = strr.find("*/");
					if (dzse != string::npos)
					{
						string str;
						str = zresult[i].replace(zresult[i].begin()+dzs, zresult[i].begin() + dzse+dzs + 2, "");
						i--;
						flag = 0;
					}
					else
					{
						str = zresult[i].replace(zresult[i].begin() + dzs, zresult[i].end(), "");
						if (flag2 == 1)
						{
							if (result.size() != 0)
							{
								result[result.size() - 1] += str;
							}
							else
							{
								if (str != "")
								{
									result.push_back(str);
								}
							}
							flag2 = 0;
						}
						else
						{
							if (str!= "")
							{
								result.push_back(str);
							}
						}
						flag = 1;
					}
				}
			}
			else
			{
				if (flag2 == 1)
				{
					if (result.size()!=0)
					{
						result[result.size() - 1] += zresult[i];
					}
					else
					{
						if (zresult[i] != "")
						{
							result.push_back(zresult[i]);
						}
					}
					flag2 = 0;
				}
				else
				{
					if (zresult[i] != "")
					{
						result.push_back(zresult[i]);
					}
				}
			}
		}
		else
		{
			dzse = zresult[i].find("*/");
			if (dzse != string::npos)
			{
				string str;
				str = zresult[i].replace(zresult[i].begin(), zresult[i].begin() + dzse + 2, "");
				i--;
				flag2 = 1;
				flag = 0;
			}
		}
	}
	return result;
}