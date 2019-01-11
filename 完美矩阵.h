/*
遇到矩阵想到面积，完美矩阵有两个条件：（1）除去最外层4个顶点，其他点成对出现（2）小矩阵面积等于最外层4点所求的面积。
*/
bool isRectangleCover(vector<vector<int>>& rectangles) {
	set<pair<int, int>> point;
	int sum = 0;
	for (int i = 0; i < rectangles.size(); i++)
	{
		sum = sum + (rectangles[i][2] - rectangles[i][0])*(rectangles[i][3] - rectangles[i][1]);
		if (point.find(pair<int, int>(rectangles[i][0], rectangles[i][1])) == point.end())
			point.insert(pair<int, int>(rectangles[i][0], rectangles[i][1]));
		else
			point.erase(pair<int, int>(rectangles[i][0], rectangles[i][1]));
		if (point.find(pair<int, int>(rectangles[i][2], rectangles[i][1])) == point.end())
			point.insert(pair<int, int>(rectangles[i][2], rectangles[i][1]));
		else
			point.erase(pair<int, int>(rectangles[i][2], rectangles[i][1]));
		if (point.find(pair<int, int>(rectangles[i][0], rectangles[i][3])) == point.end())
			point.insert(pair<int, int>(rectangles[i][0], rectangles[i][3]));
		else
			point.erase(pair<int, int>(rectangles[i][0], rectangles[i][3]));
		if (point.find(pair<int, int>(rectangles[i][2], rectangles[i][3])) == point.end())
			point.insert(pair<int, int>(rectangles[i][2], rectangles[i][3]));
		else
			point.erase(pair<int, int>(rectangles[i][2], rectangles[i][3]));
	}
	if (point.size() == 4)
	{
		int len = 0;
		int high = 0;
		//sort(point.begin(), point.end());
		set<pair<int, int>>::iterator iter = point.begin();
		len = (*iter).first;
		high = (*iter).second;
		iter++; iter++; iter++;
		len = (*iter).first - len;
		high = (*iter).second - high;
		if (sum == len * high) return true;
	}
	return false;
}