/*
在矩阵周围扩充一层0，然后循环卷积运算，然后再进行条件判断
*/
void gameOfLife(vector<vector<int>>& board) {
	if (board.size() == 0)
		return;
	vector<vector<int>> newboard=board;
	vector<vector<int>> addboard;
	vector<int> add(board[0].size() + 2, 0);
	addboard.push_back(add);
	for (int i = 0; i < board.size(); i++)
	{
		board[i].insert(board[i].begin(), 0);
		board[i].insert(board[i].end(), 0);
		addboard.push_back(board[i]);
	}
	addboard.push_back(add);
	for(int i=1;i<addboard.size()-1;i++)
		for (int j = 1; j < addboard[0].size()-1; j++)
		{
			newboard[i - 1][j - 1] = addboard[i - 1][j - 1] + addboard[i][j - 1] + addboard[i + 1][j - 1] + addboard[i - 1][j] + addboard[i + 1][j] + addboard[i - 1][j + 1] + addboard[i][j + 1] + addboard[i + 1][j + 1];
			if (addboard[i][j] == 1)
				newboard[i - 1][j - 1] == 2 || newboard[i - 1][j - 1] == 3 ? newboard[i - 1][j - 1] = 1 : newboard[i - 1][j - 1] = 0;
			if (addboard[i][j] == 0)
				newboard[i - 1][j - 1] == 3 ? newboard[i - 1][j - 1] = 1 : newboard[i - 1][j - 1] = 0;
		}
	board = newboard;
}