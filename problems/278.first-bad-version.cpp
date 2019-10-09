// 简单 二叉搜索，mid为错误版本r=mid-1,否则l=mid+1,结束后，mid如果是错误版本，向左找正确版本，否则向右找错误版本。
// 错误了一次，因为越界，mid=(l+r)/2; 容易越界，改为 mid=((long)l+r)/2;
// 16:44
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
	int firstBadVersion(int n) {
		int l = 0, r = n, mid;
		while (l <= r)
		{
			mid = ((long)l + r) / 2;
			if (isBadVersion(mid)) r = mid - 1;
			else {
				l = mid + 1;
			}
		}
		mid = ((long)l + r) / 2;
		if (isBadVersion(mid)) {
			for (int i = mid - 1; i >= 0; i--) {
				if (!isBadVersion(i)) return i + 1;
			}
		}
		else {
			for (int i = mid + 1; i <= n; i++) {
				if (isBadVersion(i)) return i;
			}
		}
		return 0;
	}
};