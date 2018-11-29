/*
计算K个鸡蛋M个step所能到达的最高楼层dp[m][k]

如果在某个楼层丢鸡蛋破了，那么就继续检查dp[m-1][k-1]

如果没破，那就检查dp[m][k-1];

状态转移方程为：dp[m][k]=1+dp[m-1][k-1]+dp[m][k-1];

dp[m][k] = dp[m-1][k-1] + dp[m-1][k] + 1 其实只用到dp[m-1][k]一次
我们可以把dp[m-1][k]写在左边
dp[m-1][k] = dp[m-1][k-1] + dp[m-1][k] + 1
等价于
dp[m-1][k] += dp[m-1][k-1] + 1

把m看做循环次数，那么方程变为dp[k]+=dp[k-1]+1;

*/
int superEggDrop(int K, int N) {
	vector<int> dp(K+1);
	int step = 0;
	while(dp[K] < N) {
		for (int i = K; i > 0; i--)
			dp[i] += (1+ dp[i-1]);
		step++；
	}
	return step;
}