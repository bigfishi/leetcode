typedef long long LL;
class Solution {
public:
	int divide(int dividend, int divisor) {
		bool isNeg = dividend > 0 ^ divisor > 0;
		LL d1 = abs((LL)dividend);
		LL d2 = abs((LL)divisor);
		LL res = 0;
		while (d1 >= d2) {
			int k = d1, car = 1;
			while (k - (d2 << car) > 0)
			{
				car++;
			}
			d1 -= (d2 << (car - 1));
			res += (1 << (car - 1));
		}
		if (isNeg) {
			res = -res;
		}
		if (res > INT_MAX)
			res = INT_MAX;
		if (res < INT_MIN)
			res = INT_MIN;
		return (int)res;
	}
};