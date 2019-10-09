// 中等 需要用到求最大公约数，需要注意越界，另外，提交错了一次，因为没考虑分子分母为10的情况
typedef long long llong;
class Solution {
	int calcGcd(llong x, llong y) {
		int z = y;
		while (z)
		{
			y = x%y;
			x = z;
			z = y;
		}
		return x;
	}
	void calcFraction(int& x, int& y, int x2, int y2) {
		llong tx = x*y2 + x2*y;
		llong ty = y*y2;
		int c = calcGcd(abs(tx), ty);
		x = tx / c;
		y = ty / c;
	}
public:
	string fractionAddition(string expression) {
		int x = 0, y = 1;
		if (expression.size() == 0) return to_string(x) + "/" + to_string(y);
		int n = expression.size();
		int i = 0;
		while (i<n)
		{
			int x2, y2;
			bool isNag = false;
			if (expression[i] == '+') i++;
			if (expression[i] == '-') {
				isNag = true;
				i++;
			}
			if (i + 1 < n && expression[i + 1] >= '0' && expression[i + 1] <= '9') {
				x2 = (expression[i] - '0') * 10 + expression[i + 1] - '0';
				i += 3;
			}
			else {
				x2 = expression[i] - '0';
				i+=2;
			}
			if (isNag) x2 = -x2;
			if (i + 1 < n && expression[i + 1] >= '0' && expression[i + 1] <= '9') {
				y2 = (expression[i] - '0') * 10 + expression[i + 1] - '0';
				i++;
			}
			else {
				y2 = expression[i] - '0';
			}
			calcFraction(x, y, x2, y2);
			i++;
		}
		string res = "";
		if (x < 0) {
			res += '-';
			x = -x;
		}
		res += to_string(x) + "/" + to_string(y);
		return res;
	}
};