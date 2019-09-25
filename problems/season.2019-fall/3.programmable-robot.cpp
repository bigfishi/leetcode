// 最初的提交，超时
class Solution {
public:
	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		set<string> set;
		for (size_t i = 0; i < obstacles.size(); i++)
		{
			string s = to_string(obstacles[i][0]) + '#' + to_string(obstacles[i][1]);
			set.insert(s);
		}
		int curX = 0, curY = 0;
		long long preDis = (long long)x*x + (long long)y*y;
		while (true)
		{
			for (size_t i = 0; i < command.size(); i++)
			{
				if (command[i] == 'U') {
					curY++;
				}
				else {
					curX++;
				}
				if (curX == x&&curY == y) return true;
				string s = to_string(curX) + '#' + to_string(curY);
				if (set.count(s)) {
					return false;
				}
			}
			long long dis = (long long)(curX - x)*(curX - x) + (long long)(curY - y)*(curY - y);
			if (dis >= preDis) return false;
			preDis = dis;
		}
		return false;
	}
};
// 参考第1名的答案
// 需要注意command包含至少1个U和至少1个R
// 先执行一次command记录单次执行的u值和r值
// 再执行command，每次都检查obstacles中是否挡住了机器人
// 难点在于如何判断机器人能到终点：机器人到终点有两种可能，多次执行command结束后到终点，多次执行command然后下次执行command过程中到达终点
// 判断的精髓就是 if ((x-u)%a==0 && (y-v)%b==0 && (x-u)/a==(y-v)/b) res = true;
// 还需要注意，判断能到达终点之后不能立即跳出循环，因为过程中可能遇到obstacle
class Solution {
public:
	bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
		int a = 0, b = 0, u = 0, v = 0;
		for (auto i : command)
			if (i == 'R')a++; else b++;
		bool res = false;
		for (auto i : command) {
			for (auto j : obstacles)
				if (j[0] <= x&&j[1] <= y && (j[0] - u) % a == 0 && (j[1] - v) % b == 0 && (j[0] - u) / a == (j[1] - v) / b)
					return false;
			if ((x - u) % a == 0 && (y - v) % b == 0 && (x - u) / a == (y - v) / b)
				res = true;
			if (i == 'R') u++; else v++;
		}
		return res;
	}
};