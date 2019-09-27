// 完全没有思路，看了下解题，又是动态规划
class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size(), m = word2.size();
		if (n == 0 || m == 0) {
			return max(n, m);
		}
		int **dp = new int*[n + 1];
		for (int i = 0; i < n + 1; i++) {
			dp[i] = new int[m + 1];
		}
		for (int i = 0; i < n + 1; i++) {
			dp[i][0] = i;
		}
		for (int j = 0; j < m + 1; j++) {
			dp[0][j] = j;
		}
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				int left = dp[i][j-1] + 1;
				int up = dp[i - 1][j] + 1;
				int left_up = dp[i - 1][j - 1];
				if (word1[i-1] != word2[j-1])
					left_up++;
				dp[i][j] = min(left, min(up, left_up));
			}
		}
		return dp[n][m];
	}
};