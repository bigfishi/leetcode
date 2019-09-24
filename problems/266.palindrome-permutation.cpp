class Solution {
public:
	bool canPermutePalindrome(string s) {
		unordered_map<int, int> map;
		for (size_t i = 0; i < s.size(); i++)
		{
			map[s[i]]++;
		}
		int oddNum = 0;
		for (auto iter : map)
		{
			if (iter.second % 2)
				oddNum++;
		}
		bool res = (oddNum <= 1);
		return res;
	}
};