// 简单 dp
class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		if (n == 0) return 0;
		vector<int> dp(n + 1, 0);
		for (int i = 1; i < n; i++) {
			dp[i+1] = min(dp[i] + cost[i], dp[i-1]+cost[i-1]);
		}
		return dp[n];
	}
};