// 简单 循环
class Solution {
public:
	int tribonacci(int n) {
		if (n < 2) return n;
		if (n == 2) return 1;
		int pre1 = 0, pre2 = 1, pre3 = 1;
		int res = 0;
		int count = n - 2;
		while (count)
		{
			--count;
			res = pre1 + pre2 + pre3;
			pre1 = pre2;
			pre2 = pre3;
			pre3 = res;
		}
		return res;
	}
};