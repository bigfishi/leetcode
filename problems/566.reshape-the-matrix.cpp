// 需要注意，计算新矩阵ij时，需要用列数c，而不是行数r
class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		if (nums.size() == 0 || nums[0].size() == 0) return nums;
		int n = nums.size(), m = nums[0].size();
		if (n == r && m == c || n*m != r*c) return nums;
		vector<vector<int>> res(r, vector<int>(c, 0));
		int index = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int i2 = index/c;
				int j2 = index%c;
				res[i2][j2] = nums[i][j];
				index++;
			}
		}
		return res;
	}
};