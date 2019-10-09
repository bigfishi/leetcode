// 中等 参考59，用l/r/t/b 4个方向
class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> res;
		if (matrix.size() == 0 || matrix[0].size() == 0) return res;
		int n = matrix.size();
		int m = matrix[0].size();
		int l = 0, r = m - 1, t = 0, b = n - 1;
		for (int i = 0; i < n*m; i++) {
			for (int j = l; j <= r; j++) res.push_back(matrix[t][j]);
			t++;
			if (res.size() == n*m) break;
			for (int j = t; j <= b; j++) res.push_back(matrix[j][r]);
			r--;
			if (res.size() == n*m) break;
			for (int j = r; j >= l; j--) res.push_back(matrix[b][j]);
			b--;
			if (res.size() == n*m) break;
			for (int j = b; j >= t; j--) res.push_back(matrix[j][l]);
			l++;
			if (res.size() == n*m) break;
		}
		return res;
	}
};