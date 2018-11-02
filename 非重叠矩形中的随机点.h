/*
思路是先随机选取一个矩阵，然后再随机在矩阵上选取一个点
选取矩阵的方法是跟面积为标准？（我也不知道为什么不能直接按索引随机）
*/
Solution(vector<vector<int>> rects) {
        _rects = rects;
    } 
vector<int> pick() {
	int sumArea = 0;
	vector<int> selected;
	//按面积随机选取矩阵
	for (auto rect : _rects) {
		int area = (rect[2] - rect[0] + 1) * (rect[3] - rect[1] + 1);
		sumArea += area;
		if (rand() % sumArea < area) selected = rect;
	}
	int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
	int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
	return {x, y};
}
private:
    vector<vector<int>> _rects;