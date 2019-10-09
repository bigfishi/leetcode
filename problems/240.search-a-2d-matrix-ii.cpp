// 中等 最初思路是第1行二叉搜索，找不到的话，通过(l+r)/2获得某列，然后在这列二叉搜索，结果有case过不去，改成逐行二叉搜索。20分钟
class Solution {
	bool binarySearch(vector<vector<int>>& matrix, int target, int row) {
		int l = 0, r = matrix[row].size() - 1, mid;
		while (l<=r)
		{
			mid = (l + r) / 2;
			if (target == matrix[row][mid]) return true;
			else if (target > matrix[row][mid]) l = mid + 1;
			else r = mid - 1;
		}
		return false;
	}
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0) return false;
		int n = matrix.size();
		for (int i = 0; i < n; i++)
			if (binarySearch(matrix, target, i)) return true;
		return false;
	}
};