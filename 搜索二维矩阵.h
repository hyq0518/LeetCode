/*
二次二分搜索
*/
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		if (matrix[0].size() == 0)
			return false;
		int left = 0;
		int right = matrix.size() - 1;
		int mid = 0;
		int x = 0;
		while (left<right)
		{
			mid = left + (right -left) / 2;
			if (matrix[mid][0] >= target)
			{
				right = mid;
			}
			else
			{
				left = mid+1;
			}
		}
		if (matrix[left][0] <= target || left == 0)
		{
			x = left;
		}
		else
		{
			x = left - 1;
		}
		left = 0;
		right = matrix[0].size() - 1;
		while (left<right)
		{
			mid = left + (right - left) / 2;
			if (matrix[x][mid] >= target)
			{
				right = mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		if (matrix[x][left] == target)
		{
			return true;
		}
		else
		{
			return false;
		}
	}