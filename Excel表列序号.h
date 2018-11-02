	/*
	基本思路是进制转换，相当将26进制转换为10进制
	*/
	int titleToNumber(string s) {
		int result=0;
		string::iterator t;
		t = s.begin();
		int len = s.length();
		while (t != s.end())
		{
			int num=0;
			num = *t - 'A' + 1;
			result += pow(26, len - 1)*num;//每一位乘对应位的进制值
			len--;
			t++;
		}
		return result;
	}