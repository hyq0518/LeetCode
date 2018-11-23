/*
注意两个条件
*/
vector<string> splitStr(string str, char delimiter) {
	vector<string> r;
	string tmpstr;
	while (!str.empty()) {
		int ind = str.find_first_of(delimiter);
		if (ind == -1) {
			r.push_back(str);
			str.clear();
		}
		else {
			r.push_back(str.substr(0, ind));
			str = str.substr(ind + 1, str.size() - ind - 1);
		}
	}
	return r;
}
string simplifyPath(string path) {
	if (path.length() == 0)
		return path+'/';
	vector<string> vpath=splitStr(path,'/');
	vector<string> result;
	for (int i = 0; i < vpath.size(); i++)
	{
		if (vpath[i]!="."&& vpath[i] != "")
		{
			result.push_back(vpath[i]);
		}
	}
	vpath.clear();
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] != "..")
		{
			vpath.push_back(result[i]);
		}
		else
		{
			if (vpath.size() != 0)
			{
				vpath.pop_back();
			}
		}
	}
	string res="";
	for (int i = 0; i < vpath.size(); i++)
	{
		res += '/'+vpath[i];
	}
	if (res.length()==0)
	{
		res += "/";
	}
	return res;
}