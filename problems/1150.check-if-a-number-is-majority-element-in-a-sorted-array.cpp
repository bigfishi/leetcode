// 简单，用count计数或者摩尔投票法都可以
class Solution {
public:
	bool isMajorityElement(vector<int>& nums, int target) {
		int x = target, cx = 0;
		for (auto num : nums) {
			if (num == x) cx++;
			else cx--;
		}
		return cx > 0;
	}
};