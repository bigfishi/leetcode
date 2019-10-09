// 简单 没想出来如何减少加法的次数，就用嘴直接的方法，不过测试的时候错了一次，边界情况的问题，改之前是i2 < min(n, i+1)和j2< min(m, j+1)。
// i+1和j+1都需要遍历到，所以改为i+2和j+2
class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int n = M.size();
		int m = M[0].size();
		vector<vector<int>> res(n, vector<int>(m,0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int count = 0;
				int sum = 0;
				for (int i2 = max(0, i - 1); i2 < min(n, i + 2); i2++) {
					for (int j2 = max(0, j - 1); j2 < min(m, j + 2); j2++) {
						sum += M[i2][j2];
						count++;
					}
				}
				res[i][j] = sum / count;
			}
		}
		return res;
	}
};
// 看了其他人解法，有2点启发，1.偏移量可以用偏移数组，更直白
// 2.矩阵整数范围是[0,255]，周围数最多8个，可以用2^11表示，如果题目要求不能用S(n)空间，则可以将矩阵每个点分为自己点的值(0~8~),周围点的和(9~19~),周围点数量(20~22~)
// S(1)空间复杂度的方法
class Solution {
public:
	vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
		int n = M.size();
		int m = M[0].size();
		int mask = 255;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				for (int i2 = max(0, i - 1); i2 < min(n, i + 2); i2++)
					for (int j2 = max(0, j - 1); j2 < min(m, j + 2); j2++)
					{
						M[i][j] += (M[i2][j2] & mask) << 12;
						M[i][j] += 1 << 8;
					}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int count = (M[i][j] >> 8)&15;
				M[i][j] = (M[i][j] >> 12) / count;
			}
		return M;
	}
};