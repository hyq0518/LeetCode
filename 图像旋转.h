/*
转秩对称，转圈圈
*/
void rotate(vector<vector<int>>& matrix) {
	int len = matrix.size();
	for (int i = 0; i < len / 2; i++)
	{
		for (int j = i; j < len -i-1; j++)
		{
			int temp = 0;
			int temp1 = 0;
			temp = matrix[j][len - 1 - i];
			matrix[j][len - 1 - i] = matrix[i][j];
			temp1 = matrix[len - 1 - i][len - 1 - j];
			matrix[len - 1 - i][len - 1 - j] = temp;
			temp = matrix[len - 1 - j][i];
			matrix[len - 1 - j][i] = temp1;
			matrix[i][j] = temp;
		 }
	}
}