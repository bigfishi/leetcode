// 45分钟，难度还行，就是手生。1.以数组为大整数的数的除法，2.越界问题
// 当前程序是除以2，是否可以除以10，加快运行效率
class Solution {
	void vecDidTwo(vector<int>& b, int& mod) {
		if (b.size() == 0) return;
		int w = 0;
		bool isBegin = true;
		for (size_t i = 0; i < b.size(); i++)
		{
			if (b[i] == -1) continue;
			int t = b[i] + w*10;
			w = t % 2;
			b[i] = t / 2;
			if (isBegin)
				if (b[i] == 0)
					b[i] = -1;
				else
					isBegin = false;
		}
		mod = w;
	}
public:
	int superPow(int a, vector<int>& b) {
		static int m = 1337;
		long res = 1;
		long cur = a;
		vector<int> modList;
		while (b.back()!=-1)
		{
			int mod = 0;
			vecDidTwo(b, mod);
			modList.push_back(mod);
		}
		for (size_t i = 0; i < modList.size(); i++)
		{
			if (modList[i])
				res = (res * cur) % m;
			cur = (cur%m)*(cur%m);
		}
		return (int)res;
	}
};
// 改为以10为间隔
class Solution {
	const int BE_MOD = 1337;
	int calcPow(int m, int n) {
		long num = 1;
		for (int i = 0; i < n; i++)
		{
			num = (num*(m%BE_MOD))%BE_MOD;
		}
		return num;
	}
public:
	int superPow(int a, vector<int>& b) {
		long res = 1;
		int w = a;
		int n = b.size();
		for (int i = n - 1; i >= 0; i--)
		{
			int t = calcPow(w, b[i]);
			res = res * t % BE_MOD;
			w = calcPow(w, 10);
		}
		return (int)res;
	}
};