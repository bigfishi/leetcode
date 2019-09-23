// 二分查找
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 0) return 0;
		if (x == 1) return 1;
		int left = 0;
		int right = x >> 1;
		while (left<right)
		{
			int mid = (left + right + 1) >> 1;
			long t = (long)mid*mid;
			if (t > x)
				right = mid - 1;
			else if (t < x)
				left = mid;
			else
				return mid;
		}
		return left;
	}
};
// 牛顿迭代法求开方，效果更好
class Solution {
public:
	int mySqrt(int x) {
		if (x <= 0) return 0;
		long n = x;
		while (n*n>x)
		{
			n = (n + x / n) / 2;
		}
		int res = (int)n;
		return res;
	}
};