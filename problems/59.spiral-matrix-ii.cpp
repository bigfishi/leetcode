// 中等 思路是有的，一直做一直错，做了60分钟
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		if (n < 1) return res;
		int num = (n + 1) / 2;
		int cur = 0;
		for (int i = 0; i < num; i++) {
			int len = n - i * 2;
			int c = max(1, len * 4 - 4);
			for (int j = 0; j < c; j++) {
				cur++;
				int row = 0, col = 0;
				if (j < len) {
					row = i;
					col = j+i;
				}
				else if (j >= len && j < len * 2 - 2) {
					row = j - len + 1 + i;
					col = n - i - 1;
				}
				else if (j >= len * 2 - 2 && j < len * 3 - 2) {
					row = n - i - 1;
					col = n - (j - len * 2 + 2) - 1 - i;
				}
				else {
					row = n - (j - len * 3 + 3) - 1 - i;
					col = i;
				}
				res[row][col] = cur;
			}
		}
		return res;
	}
};
// 有更优雅的方法，定义4个变量，l/r/t/b表示4个边界
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		if (n < 1) return res;
		int l = 0, r = n - 1, t = 0, b = n - 1;
		int cur = 0, tar = n*n;
		while (cur<tar)
		{
			for (int i = l; i <= r; i++) res[t][i] = ++cur;
			t++;
			for (int i = t; i <= b; i++) res[i][r] = ++cur;
			r--;
			for (int i = r; i >= l; i--) res[b][i] = ++cur;
			b--;
			for (int i = b; i >= t; i--) res[i][l] = ++cur;
			l++;
		}
		return res;
	}
};
// 巧妙的方法，但难想

/*

参考大牛写的, 判断何时转向的思想很巧妙
1, 有两个方向, 所以使用二维元组存储方向状态
上右 : (0, 1), 右下(1, 0), 下左(0, -1), 左上(-1, 0)
2, 判断如何转向
读取数据时, 每行, 列的最后一个元素是将要读取的列, 行的起点.
起点已经被读取, 就想到取模操作可以得到当前列, 行的下一步状态.
*/

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> res(n, vector<int>(n, 0));
		if (n < 1) return res;
		int x = 0, y = 0, dx = 0, dy = 1;
		for (int i = 1; i <= n*n; i++) {
			res[x][y] = i;
			if (res[(x + dx) % n][(y + dy) % n]>0) {
				int tmp = dx;
				dx = dy;
				dy = -tmp;
			}
			x += dx;
			y += dy;
		}
		return res;
	}
};