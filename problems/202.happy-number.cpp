// 逻辑不难，做的时候出了一次错，因为循环结束条件判断错误，原来的判断是当前数小于10，后来改成不等于1。对于永不结束的情况，用set避免
class Solution {
public:
	bool isHappy(int n) {
		if (n < 1) return false;
		int sum = 0;
		int n2 = n;
		set<int> s{ n2 };
		while (n2!=1)
		{
			sum = 0;
			while (n2) {
				int t = n2 % 10;
				n2 /= 10;
				sum += t*t;
			}
			n2 = sum;
			if (s.find(n2) != s.end()) break;
			else s.insert(n2);
		}
		return n2 == 1;
	}
};