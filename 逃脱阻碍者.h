/*
看谁先到终点
*/
bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
	if (ghosts.size() == 0)
		return true;
	int distance = 0;
	distance = abs(target[0]) + abs(target[1]);
	for (int i = 0; i < ghosts.size(); i++)
	{
		int gdistance = 0;
		gdistance=abs(ghosts[i][0] - target[0]) + abs(ghosts[i][1] - target[1]);
		if (gdistance <= distance)
			return false;
	}

	return true;
}