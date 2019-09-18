// 刚开始一直没思路，在接触的很多dfs中，都没有在循环内调用dfs的，没想到这题就是。当时抱着超时的想法做，没想到这个方法就是正常解法
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int res = 0;
		int x = 0, y = 0;
		for (size_t i = 0; i < grid.size(); i++)
		{
			for (size_t j = 0; j < grid[i].size(); j++)
			{
				if (dfs(grid, i, j))
					res++;
			}
		}
		return res;
	}
private:
	vector<int> posX{ 0, 0, 1, -1 };
	vector<int> posY{ 1, -1, 0, 0 };
	bool dfs(vector<vector<char>>& grid, int x, int y) {
		if (grid[x][y] == '0' || grid[x][y] == '#') return false;
		grid[x][y] = '#';
		for (size_t i = 0; i < posX.size(); i++)
		{
			int x2 = x + posX[i];
			int y2 = y + posY[i];
			if (x2 >= 0 && x2 < grid.size() && y2 >= 0 && y2 < grid[x2].size()) {
				dfs(grid, x2, y2);
			}
		}
		return true;
	}
};
// 思考之后，发现这题dfs的作用是把代表陆地的1修改掉，加快速度的方式是减少函数调用，在外部判断是否为1
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0) return 0;
		int res = 0;
		int n = grid.size();
		int m = grid[0].size();
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				if (grid[i][j] == '1') {
					dfs(grid, i, j);
					res++;
				}
			}
		}
		return res;
	}
private:
	void dfs(vector<vector<char>>& grid, int x, int y) {
		grid[x][y] = '#';
		int n = grid.size();
		int m = grid[x].size();
		if (x > 0 && grid[x - 1][y] == '1')
			dfs(grid, x - 1, y);
		if (x < n - 1 && grid[x + 1][y] == '1')
			dfs(grid, x + 1, y);
		if (y > 0 && grid[x][y - 1] == '1')
			dfs(grid, x, y - 1);
		if (y < m - 1 && grid[x][y + 1] == '1')
			dfs(grid, x, y + 1);
	}
};