// 简单 循环
class Solution {
public:
	int fib(int N) {
		if (N < 2) return N;
		int res = 0;
		int pre1 = 0, pre2 = 1;
		int count = N-1;
		while (count>0)
		{
			count--;
			res = pre1 + pre2;
			pre1 = pre2;
			pre2 = res;
		}
		return res;
	}
};