// 简单 排序，然后从后向前找
class Solution {
public:
	int largestUniqueNumber(vector<int>& A) {
		if (A.size() == 0) return -1;
		if (A.size() == 1) return A.back();
		sort(A.begin(), A.end());
		int n = A.size();
		int num = A.back();
		bool isDup = false;
		for (int i = n - 2; i >= 0; i--) {
			if (A[i] != num) {
				if (!isDup) return num;
				isDup = false;
				num = A[i];
			}
			else {
				isDup = true;
			}
		}
		if (!isDup) return num;
		return -1;
	}
};