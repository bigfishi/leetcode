// 用牛顿开方法求开方，忘记了，需要多次练习
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num < 0) return false;
		long n = num;
		while (n*n>num)
		{
			n = (n + num / n) / 2;
		}
		return (n*n == num);
	}
};