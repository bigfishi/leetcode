class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		vector<vector<int>> store(matrix.size());
		for (size_t i = 0; i < matrix.size(); i++)
		{
			for (size_t j = 0; j < matrix[i].size(); j++)
			{
				store[i].push_back(0);
			}
		}
		int res = 0;
		for (size_t i = 0; i < matrix.size(); i++)
		{
			for (size_t j = 0; j < matrix[i].size(); j++)
			{
				int t = 0;
				res = max(res, dfs(matrix, store, i, j, t));
			}
		}
		return res;
	}
private:
	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& store, int x, int y, int t) {
		int preT = t;
		if (store[x][y]) {
			return t + store[x][y];
		}
		t++;
		int top = 0, btm = 0, lft = 0, rgt = 0;
		if (x > 0 && matrix[x - 1][y]>matrix[x][y]) {
			top = dfs(matrix, store, x - 1, y, t);
		}
		if (x<matrix.size() - 1 && matrix[x + 1][y]>matrix[x][y]) {
			btm = dfs(matrix, store, x + 1, y, t);
		}
		if (y > 0 && matrix[x][y - 1] > matrix[x][y]) {
			lft = dfs(matrix, store, x, y - 1, t);
		}
		if (y < matrix[x].size() - 1 && matrix[x][y + 1]>matrix[x][y]) {
			rgt = dfs(matrix, store, x, y + 1, t);
		}
		t = max(t, max(max(top, btm), max(lft, rgt)));
		store[x][y] = t - preT;
		return t;
	}
};