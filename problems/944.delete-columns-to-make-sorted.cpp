// 需要注意行和列的区别，第一次错在比对的是行不是列，第二次错在行列的循环终点颠倒了，第三次才改对
class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		if (!A.size() || !A[0].size()) return 0;
		int n = A.size();
		int m = A[0].size();
		int res = 0;
		for (size_t i = 0; i < m; i++)
		{
			for (size_t j = 1; j < n; j++)
			{
				if (A[j-1][i]>A[j][i]) {
					res++;
					break;
				}
			}
		}
		return res;
	}
};