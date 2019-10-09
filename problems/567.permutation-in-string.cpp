// 哈希表和双指针(滑动窗口)。刚开始的思路是双指针在两侧，同时向中间收缩，提交发现有些情况覆盖不到，改为滑动窗口，窗口长度恒为s1长度
class Solution {
	inline bool isMapEqual(unordered_map<char, int>& m1, unordered_map<char, int>& m2) {
		if (m1.size() != m2.size()) {
			return false;
		}
		for (auto item : m1)
			if (m2.find(item.first) == m2.end() || m2[item.first] != item.second)
				return false;
		return true;
	}
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.size() == 0) return true;
		if (s1.size() > s2.size()) return false;
		unordered_map<char, int> m1, m2;
		for (auto ch : s1) m1[ch]++;
		int n = s2.size();
		int left = 0, right = s1.size()-1;
		while (right<n)
		{
			if (right == s1.size() - 1) {
				for (int i = left; i <= right; i++)
					m2[s2[i]]++;
			}
			else {
				m2[s2[right]]++;
			}
			if (isMapEqual(m1, m2))
				return true;
			if (m2[s2[left]] == 1)
				m2.erase(s2[left]);
			else
				m2[s2[left]]--;
			left++;
			right++;
		}
		return false;
	}
};