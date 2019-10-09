// 简单 需要注意1的次方恒为1
class Solution {
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		map<int, bool> m;
		vector<int> res;
		if (x == 1 && y == 1) {
			if (bound >= 2)
				res.push_back(2);
			return res;
		}
		else if (x == 1 || y == 1) {
			x = max(x, y);
			y = 1;
		}
		for (int i = 0;; i++) {
			int a = pow(x, i);
			if (a >= bound) break;
			if (y == 1) {
				if (a + y > bound) break;
				m[a + y] = true;
			}
			else {
				for (int j = 0;; j++) {
					int b = pow(y, j);
					if (a + b > bound) break;
					m[a + b] = true;
				}
			}
		}
		for (auto item : m)
			res.push_back(item.first);
		return res;
	}
};