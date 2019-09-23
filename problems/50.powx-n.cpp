class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0) return 1;
		if (x == 1) return x;
		long n2 = abs((long)n);
		if (x == -1)
			if (n2 % 2)
				return x;
			else
				return -x;
		double res = 1;
		double cur = x;
		while (n2)
		{
			int mod = n2 % 2;
			n2 >>= 1;
			if (mod)
				res *= cur;
			cur *= cur;
		}
		if (n < 0)
			if (x != 0)
				res = 1 / res;
		return res;
	}
};