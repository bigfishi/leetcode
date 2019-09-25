// 最初的提交，错误，第1不需要考虑负数，第2运行过程中分子不应该是cont[i]*y+1，而是cont[i]*y+x
typedef long long LL;
class Solution {
	inline LL gys(LL x, LL y) {
		int z = y;
		while (x%y!=0)
		{
			z = x%y;
			x = y;
			y = z;
		}
		return z;
	}
public:
	vector<int> fraction(vector<int>& cont) {
		vector<int> res;
		if (cont.size() == 0) return res;
		if (cont.size() == 1) {
			res.push_back(cont[0]);
			res.push_back(1);
			return res;
		}
		if (cont.size() == 2) {
			int x = cont[0] * cont[1] + 1;
			int y = cont[1];
			int t = gys(x, y);
			res.push_back(x / t);
			res.push_back(y / t);
		}
		int n = cont.size();
		long long x = 0; // 分子
		long long y = cont[n - 1];	// 分母
		bool isBegin = true;
		for (int i = n-2; i >= 0; i--)
		{
			if (isBegin) {
				isBegin = false;
				if (y < 0) {
					y = -y;
					x = cont[i] * y - 1;
				}
				else {
					x = cont[i] * y + 1;
				}
				if (x < 0) {
					x = -x;
					y = -y;
				}
				int t = gys(abs(x), abs(y));
				if (t > 1) {
					x /= t;
					y /= t;
				}
			}
			else {
				int t;
				if (y < 0) {
					y = -y;
					t = cont[i] * x - y;
				}
				else {
					t = cont[i] * x + y;
				}
				y = x;
				x = t;
				if (x < 0) {
					x = -x;
					y = -y;
				}
				t = gys(abs(x), abs(y));
				if (t > 1) {
					x /= t;
					y /= t;
				}
			}
		}
		res.push_back(x);
		res.push_back(y);
		return res;
	}
};
// 参考第1名的提交
typedef long long llong;
class Solution {
	inline llong myGcd(llong a, llong b) {
		return (b == 0) ? a : myGcd(b, a%b);
	}
public:
	vector<int> fraction(vector<int>& cont) {
		int n = cont.size();
		llong x = cont[n - 1], y = 1, t;	// x 分子 y 分母
		for (int i = n - 2; i >= 0; i--) {
			swap(x, y);
			x += cont[i] * y;
			t = myGcd(x, y);
			x /= t;
			y /= t;
		}
		vector<int> res;
		res.push_back(int(x));
		res.push_back(int(y));
        return res;
	}
};