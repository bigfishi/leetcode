// 简单 dp
class Solution {
public:
	int climbStairs(int n) {
		if (n <= 0) return 0;
		vector<int> dp(n+1, 0);
		dp[1] = 1;
		for (int i = 1; i < n; i++) {
			dp[i + 1] = max(dp[i], 1) + max(dp[i - 1], 1);
		}
		int res = dp[n];
		return res;
	}
};