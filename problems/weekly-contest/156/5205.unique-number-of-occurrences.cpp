// 这题考察哈希表，用unordered_map记录每个字符出现的次数，把所有次数放入list，并排序，遍历，检查是否有重复数即可。
class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> map;
		for (auto num : arr)
			map[num]++;
		vector<int> list;
		for (auto item : map) {
			list.push_back(item.second);
		}
		sort(list.begin(), list.end());
		for (int i = 1; i < list.size(); i++) {
			if (list[i - 1] == list[i]) {
				return false;
			}
		}
		return true;
	}
};