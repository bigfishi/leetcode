// 中等 获得交换一次字典序小于A的最大可能序列，而不是获得小于A的最大可能序列
class Solution {
public:
	vector<int> prevPermOpt1(vector<int>& A) {
		int n = A.size();
		int i;
		for (i = n - 2; i >= 0; i--) {
			if (A[i] > A[i + 1]) {
				break;
			}
		}
		if (i < 0) return A;
		int minIndex = i + 1, min = INT_MIN;
		for (int j = i + 1; j < n; j++) {
			if (A[j]<A[i] && A[j]>min) {
				min = A[j];
				minIndex = j;
			}
		}
		swap(A[i], A[minIndex]);
		// sort(A.begin() + i + 1, A.end(), greater<>());
		return A;
	}
};