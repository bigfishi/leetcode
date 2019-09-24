// dfs方法，速度太慢，超过时间限制
class Solution {
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		vector<vector<bool>> record(maze.size(), vector<bool>(maze[0].size(), false));
		int res = -1;
		int curStep = 0;
		record[start[0]][start[1]] = 1;
		dfs(maze, record, start, destination, curStep, res);
		return res;
	}
private:
	void dfs(vector<vector<int>>& maze, vector<vector<bool>>& record, vector<int>& start, vector<int>& destination, int& curStep, int& step) {
		if (start[0] == destination[0] && start[1] == destination[1]) {
			if (step == -1) {
				step = curStep;
			}
			else {
				step = min(step, curStep);
			}
			return;
		}
		int x = start[0], y = start[1];
		int x2, y2;
		// top
		x2 = x;
		y2 = y;
		if (x2 > 0 && maze[x2 - 1][y2] == 0) {
			bool canMove = true;
			while (x2>0 && maze[x2 - 1][y2] == 0)
			{
				x2--;
			}
			if (canMove && record[x2][y2]) {
				canMove = false;
			}
			if (canMove) {
				record[x2][y2] = 1;
				curStep += x - x2;
				vector<int> start2{ x2, y2 };
				dfs(maze, record, start2, destination, curStep, step);
				curStep -= x - x2;
				record[x2][y2] = 0;
			}
		}
		// bottom
		x2 = x;
		y2 = y;
		if (x2 < maze.size() - 1 && maze[x2 + 1][y2] == 0) {
			bool canMove = true;
			while (x2<maze.size() - 1 && maze[x2 + 1][y2] == 0)
			{
				x2++;
			}
			if (canMove && record[x2][y2]) {
				canMove = false;
			}
			if (canMove) {
				record[x2][y2] = 1;
				vector<int> start2{ x2, y2 };
				curStep += x2 - x;
				dfs(maze, record, start2, destination, curStep, step);
				curStep -= x2 - x;
				record[x2][y2] = 0;
			}
		}
		// left
		x2 = x;
		y2 = y;
		if (y2 > 0 && maze[x2][y2 - 1] == 0) {
			bool canMove = true;
			while (y2>0 && maze[x2][y2 - 1] == 0)
			{
				y2--;
			}
			if (canMove && record[x2][y2]) {
				canMove = false;
			}
			if (canMove) {
				record[x2][y2] = 1;
				vector<int> start2{ x2, y2 };
				curStep += y - y2;
				dfs(maze, record, start2, destination, curStep, step);
				curStep -= y - y2;
				record[x2][y2] = 0;
			}
		}
		// right
		x2 = x;
		y2 = y;
		if (y2 < maze[x2].size() - 1 && maze[x2][y2 + 1] == 0) {
			bool canMove = true;
			while (y2<maze[x2].size() - 1 && maze[x2][y2 + 1] == 0)
			{
				y2++;
			}
			if (canMove && record[x2][y2]) {
				canMove = false;
			}
			if (canMove) {
				record[x2][y2] = 1;
				vector<int> start2{ x2, y2 };
				curStep += y2 - y;
				dfs(maze, record, start2, destination, curStep, step);
				curStep -= y2 - y;
				record[x2][y2] = 0;
			}
		}
	}
};
// 学完dfs之后的解法，还是超时
class Solution {
	int moveX[4];
	int moveY[4];
	void stepPath(vector<vector<int>>& maze, vector<vector<bool>>& visited, vector<int>& start, vector<int>& destination, int& res, int cur) {
		if (start[0] == destination[0] && start[1] == destination[1]) {
			res = min(res, cur);
			return;
		}
		int x = start[0], y = start[1];
		visited[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int cur2 = cur;
			int deltaX = moveX[i];
			int deltaY = moveY[i];
			int x2 = x, y2 = y;
			while (x2 + deltaX >= 0 && x2 + deltaX<maze.size() && y2 + deltaY >= 0 && y2 + deltaY<maze[0].size() && maze[x2 + deltaX][y2 + deltaY] == 0)
			{
				x2 += deltaX;
				y2 += deltaY;
				cur2++;
			}
			if (x2 == x && y2 == y)
				continue;
			if (visited[x2][y2])
				continue;
			vector<int> t{ x2, y2 };
			stepPath(maze, visited, t, destination, res, cur2);
		}
		visited[x][y] = false;
	}
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		if (maze.size() == 0 || maze[0].size() == 0) return -1;
		vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
		int res = INT_MAX;
		int cur = 0;
		moveX[0] = 1, moveX[1] = -1, moveX[2] = 0, moveX[3] = 0;
		moveY[0] = 0, moveY[1] = 0, moveY[2] = 1, moveY[3] = -1;
		stepPath(maze, visited, start, destination, res, cur);
		if (res == INT_MAX) res = -1;
		return res;
	}
};

// 通过，参考 dp的方法 https://leetcode-cn.com/problems/the-maze-ii/solution/bfsjie-jue-by-xiao-hun-tun-3/
class Solution {
	int moveX[4];
	int moveY[4];
public:
	int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
		if (maze.size() == 0 || maze[0].size() == 0) return -1;
		int n = maze.size();
		int m = maze[0].size();
		moveX[0] = 1, moveX[1] = -1, moveX[2] = 0, moveX[3] = 0;
		moveY[0] = 0, moveY[1] = 0, moveY[2] = 1, moveY[3] = -1;
		vector<vector<int>> dp(n, vector<int>(m, 0));	// 记录步数
		queue<pair<int, int>> q;
		q.push(make_pair(start[0], start[1]));
		int r, c, tmpr, tmpc, steps;
		while (q.size())
		{
			auto t = q.front();
			q.pop();
			r = t.first, c = t.second;
			// 上下左右方向的搜索，steps记录总步数
			// 如果步数优于dp中的步数，需要重新入队
			for (int i = 0; i < 4; i++)
			{
				tmpr = r, tmpc = c;
				int deltaX = moveX[i];
				int deltaY = moveY[i];
				while (tmpr + deltaX >= 0 && tmpr + deltaX<maze.size() && tmpc + deltaY >= 0 && tmpc + deltaY<maze[0].size() && maze[tmpr + deltaX][tmpc + deltaY] == 0)
				{
					tmpr += deltaX;
					tmpc += deltaY;
				}
				steps = abs(tmpr - r) + abs(tmpc - c) + dp[r][c];
				if ((tmpr != r || tmpc != c) && (!dp[tmpr][tmpc] || steps < dp[tmpr][tmpc])) {
					q.push(make_pair(tmpr, tmpc));
					dp[tmpr][tmpc] = steps;
				}
			}
		}
		// 如果最后dp数组中目标位置为0，说明还没走过，肯定是走不到了
		if (dp[destination[0]][destination[1]] == 0) {
			return -1;
		}
		else {
			return dp[destination[0]][destination[1]];
		}
	}
};