/*
(动态规划) O(n2m)O(n2m)
设状态 f(t,x,y)f(t,x,y) 表示 tt 时刻，老鼠位于 xx 且猫位于 yy 时的结果（0，1 或 2）。
如果当前为老鼠行动，那么他可以走到 f(t+1,i,y),i∈graph[x]f(t+1,i,y),i∈graph[x]，如果他走到的这些点结果都是 2，则老鼠必输无疑；若其中有一个是 1，则老鼠必获胜；否则结果就是平局。
对于猫来说，以上分析相反。
我们已经知道的状态有，f(t,0,y)=1f(t,0,y)=1，f(t,x,x)=2f(t,x,x)=2，分别代表老鼠获胜和猫获胜。
若游戏进行了 2n2n 个单位时间还没有结束，则可以宣布平局（待证明，以下为直觉想法）。因为每一次移动老鼠都有可能到达一个新的位置，所以它最多只需要 2n2n 步就可能找到出口（因为猫对应也走了 nn 步）。若超过了 2n2n 步，则老鼠必定走了回头路，此时不管猫在哪，走回头路都是向猫 “妥协” 的选择；同理对猫来说，走回头路也是向老鼠 “妥协” 的结果；故最大的 tt 只需要 2n2n 即可。
我们从 solve(0,1,2)solve(0,1,2) 开始记忆化搜索即可。
*/
 int catMouseGame(vector<vector<int>>& graph) {
  int size = graph.size();
  vector<vector<int>> dp(size, vector<int>(size, -1));
  for (int i = 0; i < size; i++) {
	dp[0][i] = 1; // mouse reaches home, mouse wins
	dp[i][i] = 2; // cat meets mouse, cat wins
  }
  return helper(graph, 1, 2, dp);
}

int helper(const vector<vector<int>>& graph, int mouse, int cat,
		  vector<vector<int>>& dp) {
  if (dp[mouse][cat] >= 0)
	return dp[mouse][cat];
  dp[mouse][cat] = 0; // if there is a cycle, draw
  int mouseDefault = 2; // default cat wins, try to update this number to 0 or 1
  const vector<int>& mouseList = graph[mouse];
  const vector<int>& catList = graph[cat];
  for (int mousePos : mouseList) {
	if (mousePos == cat)   // avoid cat
	  continue;
	int catDefault = 1; // default mouse wins, try to update to 0 or 2
	for (int catPos : catList) {
	  if (catPos == 0)
		continue;
	  int next = helper(graph, mousePos, catPos, dp);
	  if (next == 2) { // if cat wins
		catDefault = 2;
		break;
	  } else if (next == 0) {
		catDefault = 0;
	  }
	}
	if (catDefault == 1) {  // if mouse can win
	  mouseDefault = 1;
	  break;
	} else if (catDefault == 0) {
	  mouseDefault = 0;
	}
  }
  dp[mouse][cat] = mouseDefault;
  return mouseDefault;
}