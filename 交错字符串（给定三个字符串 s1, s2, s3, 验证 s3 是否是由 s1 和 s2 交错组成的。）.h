/*
交错所以s3的当前字符要么是s1的，要么是s2的。所以只需考虑这两种情况即可
如果str1的?长度为M，str2的?长度为N，经典动态规划的?方法可以达到时间复杂度O(M*N)，额
外空间复杂度O(M*N)。如果结合空间压缩的技巧可以把额外空间复杂度减?至O(min{M,N})。
先来介绍经典动态规划的?方法。?首先aim如果是str1和str2的交错组成，aim的?长度?一定是M
+N，否则直接返回false。然后?生成?大?小为(M+1)*(N+1)布尔类型的矩阵dp，dp[i][j]的值代表
aim[0..i+j-1]能否被str1[0..i-1]和str2[0..j-1]交错组成。计算dp矩阵的时候，是从左到右再
从上到下的计算的，dp[M][N]也就是dp矩阵中最右下?角的值，就表?示aim整体能否被str1整
体和str2整体交错组成，也就是最终结果。具体说明dp矩阵每个位置的值是如何计算。
1，dp[0][0]=true。aim为空串时，当然可以被str1为空串和str2为空串交错组成。
2，矩阵dp第?一列即dp[0..M-1][0]。dp[i][0]表?示aim[0..i-1]能否只被str1[0..i-1]交错组成。
如果aim[0..i-1]等于str1[0..i-1]，则令dp[i][0]=true，否则令dp[i][0]=false。
3，矩阵dp第?一?行即dp[0][0..N-1]。dp[0][j]表?示aim[0..j-1]能否只被str2[0..j-1]交错组成。
如果aim[0..j-1]等于str1[0..j-1]，则令dp[i][0]=true，否则令dp[i][0]=false。
4，对于其他位置(i,j)，dp[i][j]的值由下?面的情况决定。
1）dp[i-1][j]代表aim[0..i+j-2]能否被str1[0..i-2]和str2[0..j-1]交错组成，如果可以，
那么如果再有str1[i-1]等于aim[i+j-1]，说明str1[i-1]?又可以作为交错组成aim[0..i+j-1]的最
后?一个字符。令dp[i][j]=true。
2）dp[i][j-1]代表aim[0..i+j-2]能否被str1[0..i-1]和str2[0..j-2]交错组成，如果可以，
那么如果再有str2[j-1]等于aim[i+j-1]，说明str1[j-1]?又可以作为交错组成aim[0..i+j-1]的最
后?一个字符。令dp[i][j]=true。
3）如果情况1）和情况2）都不满?足，令dp[i][j]=false。
*/
bool isInterleave(string s1, string s2, string s3) {
	if (s3.length() != s1.length() + s2.length())
		return false;
	if (s1.length() == 0)
		return s2 == s3;
	if (s2.length() == 0)
		return s1 == s3;
	//以下代码为动态规划
	vector<vector<bool> > dp(s1.length() + 1, vector<bool>(s2.length() + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= s1.length(); i++)
		dp[i][0] = dp[i - 1][0] && (s3[i - 1] == s1[i - 1]);//
	for (int i = 1; i <= s2.length(); i++)
		dp[0][i] = dp[0][i - 1] && (s3[i - 1] == s2[i - 1]);//
	for (int i = 1; i <= s1.length(); i++)
	{
		for (int j = 1; j <= s2.length(); j++)
		{
			int t = i + j;
			if (s1[i - 1] == s3[t - 1])
				dp[i][j] = dp[i][j] || dp[i - 1][j]; //只有两种情况下匹配
			if (s2[j - 1] == s3[t - 1])
				dp[i][j] = dp[i][j] || dp[i][j - 1]; //
		}
	}
	return dp[s1.length()][s2.length()];
}
