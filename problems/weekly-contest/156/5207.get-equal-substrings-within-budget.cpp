// 这题考察的是求序列中不大于k的最长子序列的长度
class Solution {
public:
	int equalSubstring(string s, string t, int maxCost) {
		vector<int> list;
		for (int i = 0; i < s.size(); i++) {
			list.push_back(abs(s[i] - t[i]));
		}
		int res = 0, index = 0, curCost = 0, num =0;
		for (int i = 0; i < list.size(); i++) {
			curCost += list[i];
			num++;
			while (curCost>maxCost && index<=i)
			{
				curCost -= list[index];
				index++;
				num--;
			}
			res = max(res, num);
		}
		return res;
	}
};