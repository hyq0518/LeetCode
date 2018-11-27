/*
注意超过int的范围
*/
bool isPalindrome(int x) {
	if (x < 0)
		return false;
	string temp = to_string(x);
	long long res = 0;
	reverse(temp.begin(), temp.end());
	istringstream mystream(temp);
	mystream >> res;
	if (res == x)
		return true;
	else
		return false;
}