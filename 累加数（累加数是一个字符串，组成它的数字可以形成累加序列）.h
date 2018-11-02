/*
思路为：选择完第一个数字和第二数字后面的序列固定，所以只要选择前两个数字然后产出后面的序列与num比较（产生的序列要大于等于num长度）
当产生的序列与num相同时表示该数字序列为累加序列。
*/
bool isAdditiveNumber(string num) {
	if (num.length() <= 2)
	{
		return false;
	}
	for (int i = 0; i < num.length()-2; i++)//选择第一个数字
	{
		for (int j = i + 1; j < num.length() - 1; j++)//选择第二个数字
		{
			string xstring;
			string ystring;
			string addstring;
			long xlong = 0;
			long ylong = 0;
			xstring = num.substr(0,i+1);//第一个数字
			ystring = num.substr(i+1,j-i);//第二个数字
			istringstream mystringstream(xstring);
			mystringstream >> xlong;
			mystringstream = istringstream(ystring);
			mystringstream >> ylong;
			addstring += to_string(xlong) + to_string(ylong);
			while (addstring.length()<num.length())//通过第一个数字和第二数字产生完整的序列，直到产生序列长度大于等于num长度停止产生
			{
				ylong = xlong + ylong;
				xlong = ylong - xlong;
				addstring += to_string(ylong);
			}
			if (addstring == num)//判断产生序列与num是否相同，相同表示该序列为累加序列
			{
				return true;
			}
			if (num[i+1] == '0')//防止第二数字以0开头，第二个数字可以为0
			{
				break;
			}
		}
	}
	return false;
}