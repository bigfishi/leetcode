// 中等 开始想通过举例3,4,5来总结规律，发现很难。改为在Z上做文章，直接遍历字符串，每次求一次row，花费了1小时
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows < 2) return s;
		vector<string> list(numRows, "");
		int row = 0;
		for (int i = 0; i < s.size(); i++) {
			int t = i % (numRows + numRows - 2);
			if (t < numRows) {
				row = t;
			}
			else {
				row = numRows - (t - numRows + 2);
			}
			list[row] += s[i];
		}
		string res = "";
		for (auto str : list)
			res += str;
		return res;
	}
};