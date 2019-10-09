// 动态规划，迷宫问题求最短路径长度的通用解法。需要注意，蛇行动有2个方向，dp需要记录2个方向的值，难点在于切换方向的时候，设置dp的值也需要切换方向
typedef vector<pair<int, int>> vp;
class Solution {
public:
	int minimumMoves(vector<vector<int>>& grid) {
		vp start{ { 0, 0 }, { 0, 1 } };
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, 0)));
		int step = 0;
		stack<vp> st;
		st.push(start);
		while (st.size())
		{
			vp cur = st.top();
			st.pop();
			int x = cur[0].first, y = cur[0].second, x2 = cur[1].first, y2 = cur[1].second;
			int orent = 0;
			if (x != x2) orent = 1;
			if (orent == 0) { // 水平
				if (y2 + 1 < m && grid[x2][y2 + 1] == 0) {
					int x3 = x2, y3 = y2 + 1;
					step = 1 + dp[x2][y2][orent];
					if (step < dp[x3][y3][orent] || !dp[x3][y3][orent]) {
						st.push({ cur[1], { x3, y3 } });
						dp[x3][y3][orent] = step;
					}
				}
				if (x + 1 < n && grid[x + 1][y] == 0 && grid[x + 1][y2] == 0) {
					int x3 = x + 1, y3 = y2;
					step = 1 + dp[x2][y2][orent];
					if (step < dp[x3][y3][orent] || !dp[x3][y3][orent]) {
						st.push({ { x3, y }, { x3, y3 } });
						dp[x3][y3][orent] = step;
					}
				}
				if (x + 1 < n && grid[x + 1][y] == 0 && grid[x + 1][y2] == 0) {
					int x3 = x + 1, y3 = y;
					step = 1 + dp[x2][y2][orent];
					if (step < dp[x3][y3][1] || !dp[x3][y3][1]) {
						st.push({ { x, y }, { x3, y3 } });
						dp[x3][y3][1] = step;
					}
				}
			}
			else {
				if (y + 1 < m && grid[x][y + 1] == 0 && grid[x2][y2 + 1] == 0) {
					int x3 = x2, y3 = y2 + 1;
					step = 1 + dp[x2][y2][orent];
					if (step < dp[x3][y3][orent] || !dp[x3][y3][orent]) {
						st.push({ { x, y + 1 }, { x3, y3 } });
						dp[x3][y3][orent] = step;
					}
				}
				if (x2 + 1 < n && grid[x2 + 1][y2] == 0) {
					int x3 = x2 + 1, y3 = y2;
					step = 1 + dp[x2][y2][orent];
					if (step < dp[x3][y3][orent] || !dp[x3][y3][orent]) {
						st.push({ { cur[1], { x3, y3 } } });
						dp[x3][y3][orent] = step;
					}
				}
				if (y + 1 < m && grid[x][y+1] == 0 && grid[x2][y2+1] == 0) {
					int x3 = x, y3 = y+1;
					step = 1 + dp[x2][y2][orent];
					if (step < dp[x3][y3][0] || !dp[x3][y3][0]) {
						st.push({ { x, y }, { x3, y3 } });
						dp[x3][y3][0] = step;
					}
				}
			}
		}
		int res = dp[n - 1][m - 1][0];
		if (res == 0) return -1;
		else return res;
	}
};
// 按第1次的思路重写，超时了。区别就是代表贪吃蛇的点的表示方法，之前是vector<pair>，现在是vector<vector>，用超时样例测了一下，当前方法8s，之前的方法2s
class Solution {
	int dp[100][100][2];
public:
	int minimumMoves(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> start{ { 0, 0 }, { 0, 1 } };
		memset(dp, 0, sizeof(dp));
		stack<vector<vector<int>>> st;
		int step = 0;
		st.push(start);
		while (st.size())
		{
			auto cur = st.top();
			st.pop();
			int x = cur[0][0], y = cur[0][1], x2 = cur[1][0], y2 = cur[1][1];
			int orient = 0;
			if (x != x2) {
				orient = 1;
			}
			if (orient == 0) {
				if (y2 + 1 < m && grid[x2][y2 + 1] == 0) {
					int x3 = x2, y3 = y2 + 1;
					step = 1 + dp[x2][y2][orient];
					if (!dp[x3][y3][orient] || step < dp[x3][y3][orient]) {
						dp[x3][y3][orient] = step;
						vector<vector<int>> t = { cur[1], { x3, y3 } };
						st.push(t);
					}
				}
				if (x + 1 < n && grid[x + 1][y] == 0 && grid[x2 + 1][y2] == 0) {
					int x3 = x2 + 1, y3 = y2;
					step = 1 + dp[x2][y2][orient];
					if (!dp[x3][y3][orient] || step < dp[x3][y3][orient]) {
						dp[x3][y3][orient] = step;
						vector<vector<int>> t = { { x + 1, y }, { x3, y3 } };
						st.push(t);
					}
				}
				if (x + 1 < n && grid[x + 1][y] == 0 && grid[x2 + 1][y2] == 0) {
					int x3 = x + 1, y3 = y;
					step = 1 + dp[x2][y2][orient];
					if (!dp[x3][y3][1] || step < dp[x3][y3][1]) {
						dp[x3][y3][1] = step;
						vector<vector<int>> t = { cur[0], { x3, y3 } };
						st.push(t);
					}
				}
			}
			else {
				if (y + 1 < m&&grid[x][y + 1] == 0 && grid[x2][y2 + 1] == 0) {
					int x3 = x2, y3 = y2 + 1;
					step = 1 + dp[x2][y2][orient];
					if (!dp[x3][y3][orient] || step < dp[x3][y3][orient]) {
						dp[x3][y3][orient] = step;
						vector<vector<int>> t = { { x, y + 1 }, { x3, y3 } };
						st.push(t);
					}
				}
				if (x2 + 1 < n&& grid[x2+1][y2] == 0) {
					int x3 = x2+1, y3 = y2;
					step = 1 + dp[x2][y2][orient];
					if (!dp[x3][y3][orient] || step < dp[x3][y3][orient]) {
						dp[x3][y3][orient] = step;
						vector<vector<int>>t = { cur[1], { x3, y3 } };
						st.push(t);
					}
				}
				if (y2 + 1 < m&&grid[x][y + 1] == 0 && grid[x2][y2 + 1] == 0) {
					int x3 = x, y3 = y2 + 1;
					step = 1 + dp[x2][y2][orient];
					if (!dp[x3][y3][0] || step < dp[x3][y3][0]) {
						dp[x3][y3][0] = step;
						vector<vector<int>> t = { { x, y }, { x3, y3 } };
						st.push(t);
					}
				}
			}
		}
		int res = dp[n - 1][m - 1][0];
		if (res == 0) return -1;
		else return res;
	}
};
// 第1名的做法，非常快，同样的样例，上面是8s，这个是0.029s
class Solution {
	int f[105][105][2];
public:
	int minimumMoves(vector<vector<int>>& grid) {
		int n = grid.size(), i, j, ans;
		memset(f, 127, sizeof(f));
		f[0][0][0] = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (!grid[i][j])
				{
					if (i + 1 < n&&j + 1 < n&&!grid[i + 1][j] && !grid[i][j + 1] && !grid[i + 1][j + 1])
					{
						f[i][j][0] = min(f[i][j][0], f[i][j][1] + 1);
						f[i][j][1] = min(f[i][j][1], f[i][j][0] + 1);
						f[i + 1][j][0] = min(f[i + 1][j][0], f[i][j][0] + 1);
						f[i][j + 1][1] = min(f[i][j + 1][1], f[i][j][1] + 1);
					}
					if (j + 2 < n&&!grid[i][j + 1] && !grid[i][j + 2])
						f[i][j + 1][0] = min(f[i][j + 1][0], f[i][j][0] + 1);
					if (i + 2 < n&&!grid[i + 1][j] && !grid[i + 2][j])
						f[i + 1][j][1] = min(f[i + 1][j][1], f[i][j][1] + 1);
				}
		ans = f[n - 1][n - 2][0];
		if (ans == 2139062143)ans = -1;
		return ans;
	}
};
// 自己写的代码，并且有思路注释
// 难理解的地方在于点表示蛇尾，可以横纵切换时，将横纵步数根据纵横步数获取最小值，并且考虑横向向下，纵向向右的情况
// 横向需要右边2个点都是空的，右边第1个点放蛇头，纵向需要下面有2个空的，下面第1个点放蛇头
class Solution { 	// 蛇是2个点，这里只判断1个点
	int dp[100][100][2];
	const int INF = 10000000;
public:
	int minimumMoves(vector<vector<int>>& grid) {
		int n = grid.size(), i, j, res;
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				dp[i][j][0] = dp[i][j][1] = INF;
			}
		}
		dp[0][0][0] = 0;		// 初始位置，代表蛇尾，横向
		for (i = 0; i < n; i++)
			for (j = 0; j < n;j++)
				if (!grid[i][j]) {
					// 如果以当前点为左上角的2*2区域除了当前点之外的其他点都为0，在这种情况下，可以横纵切换
					if (i + 1 < n&&j + 1 < n&&!grid[i + 1][j] && !grid[i][j + 1] && !grid[i + 1][j + 1]) {
						dp[i][j][0] = min(dp[i][j][0], dp[i][j][1] + 1);	// 为什么放这里，不放在if外面，因为这2句是横纵切换的计算，在if内才可以横纵切换
						dp[i][j][1] = min(dp[i][j][1], dp[i][j][0] + 1);
						dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0] + 1);	// 蛇头在i,j+1的情况
						dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + 1);	// 蛇头在i+1,j的情况
					}
					// 横向
					if (j + 2 < n&&!grid[i][j + 1] && !grid[i][j + 2]) {
						dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][0] + 1);
					}
					// 纵向
					if (i + 2 < n&&!grid[i + 1][j] && !grid[i + 2][j]) {
						dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][1] + 1);
					}
				}
		res = dp[n - 1][n - 2][0];
		if (res == INF)
			return -1;
		else
			return res;
	}
};

class Solution {
	int dp[100][100][2];
	const int INF = 10000000;
public:
	int minimumMoves(vector<vector<int>>& grid) {
		int n = grid.size(), i, j, res;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				dp[i][j][0] = dp[i][j][1] = INF;
		dp[0][0][0] = 0;
		for (i = 0; i < n; i++)
			for (j = 0; j < n;j++)
				if (!grid[i][j]) {
					if (i + 1 < n&&j + 1 < n&&!grid[i + 1][j] && !grid[i][j + 1] && !grid[i + 1][j + 1]) {
						dp[i][j][0] = min(dp[i][j][0], dp[i][j][1] + 1);
						dp[i][j][1] = min(dp[i][j][1], dp[i][j][0] + 1);
						dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][0] + 1);
						dp[i][j + 1][1] = min(dp[i][j + 1][1], dp[i][j][1] + 1);
					}
					if (i + 2 < n&&!grid[i + 1][j] && !grid[i + 2][j])
						dp[i + 1][j][1] = min(dp[i + 1][j][1], dp[i][j][1]+1);
					if (j + 2 < n&&!grid[i][j + 1] && !grid[i][j + 2])
						dp[i][j + 1][0] = min(dp[i][j + 1][0], dp[i][j][0]+1);
				}
		res = dp[n - 1][n - 2][0];
		if (res == INF)
			return -1;
		else
			return res;
	}
};