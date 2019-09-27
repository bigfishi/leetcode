// 困难，从昨晚做到今天，看了解答在做还错了1次。整体思路是哈希表+双指针(滑动窗口) 需要注意的是word可能是由重复字符组成的，所以每次只滑动1位
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (words.size() == 0 || words[0].size()==0 || s.size() == 0) return vector<int>();
		int wordsNum = words.size();
		int wordsLen = words[0].size();
		int strLen = s.size();
		unordered_map<string, int> map;
		for (auto w : words) {
			map[w]++;
		}
		vector<int> res;
		int left;
		for (int right = wordsNum*wordsLen-1; right < strLen; right++) {
			left = right - wordsNum*wordsLen + 1;
			int i = left;
			unordered_map<string, int> tmpMap;
			while (i<=right)
			{
				string t = s.substr(i, wordsLen);
				if (map.find(t) == map.end()) {
					break;
				}
				tmpMap[t]++;
				if (map[t] < tmpMap[t]) {
					break;
				}
				i += wordsLen;
			}
			if (i >= right) {
				bool t = true;
				for (auto iter : map) {
					if (tmpMap[iter.first] != iter.second) {
						t = false;
						break;
					}
				}
				if (t) {
					res.push_back(left);
				}
			}
		}
		return res;
	}
};