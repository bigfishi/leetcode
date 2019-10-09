// 困难 参考用了回溯法
class Solution {
	int res;
	bool hasSqrt(int n) {
		if (n < 0) return false;
		if (n < 2) return true;
		long x = n;
		while (x*x>n) {
			x = (x + n / x) / 2;
		}
		bool res = (x*x==n);
		return res;
	}

	void backTrack(vector<int>& nums, int count, int pre, vector<bool>& visited) {
		if (count == nums.size()) {
			res++;
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (visited[i] || (i>0 && !visited[i - 1] && nums[i - 1] == nums[i]) || (pre != -1 && !hasSqrt(pre + nums[i]))) {
				continue;
			}
			visited[i] = true;
			backTrack(nums, count+1, nums[i], visited);
			visited[i] = false;
		}
	}
public:
	int numSquarefulPerms(vector<int>& A) {
		res = 0;
		if (A.size() < 2) return res;
		sort(A.begin(), A.end());
		vector<bool> visited(A.size(), false);
		backTrack(A, 0, -1, visited);
		return res;
	}
};