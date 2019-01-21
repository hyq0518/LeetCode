/*
异或，数往右移
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
string reverseWords(string s) {
    if(s=="")
        return s;
	vector<string> vres = splitStr(s, ' ');
	string res = "";
	for (int i = 0; i < vres.size(); i++)
	{
		reverse(vres[i].begin(), vres[i].end());
		res += vres[i]+" ";
	}
	res.erase(res.length() - 1);
	return res;
}