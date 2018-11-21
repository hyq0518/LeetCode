/*
大数相加，字符串相加
*/
int minCut(string s) {
	int n = s.size();
	vector<int> cut(n+1);
	for(int i=0; i<n+1; ++i) cut[i] = i-1; 
	int l = 0, r = 0, st = 0;
	while(st<n){
		l = r = st;
		cut[r+1] = min(cut[r+1], cut[l]+1);
		int ms = cut[l]+1;
		while(r<n-1 && s[l] == s[r+1]){ // skip the repeated chars
			++r;
			ms = min(ms, cut[r]+1);
			cut[r+1] = min(cut[r+1], ms);   
		}
		st = r+1;
		while(r<n-1 && l>0 && s[--l] == s[++r]){ // augment the repeated core to see whether it remains  Palindrome
			cut[r+1] = min(cut[r+1], cut[l] + 1);
		}
	}
	return cut[n];
}