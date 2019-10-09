// 1. 先排序，然后判断
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		sort(nums.begin(), nums.end());
		int cur = 1, res = 1, pre = nums[0];
		int res = 0;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] - pre == 1) {
				pre = nums[i];
				cur++;
				if (cur > res) {
					res = cur;
				}
			}
			else if (nums[i] == pre) {

			}
			else {
				pre = nums[i];
				cur = 1;
			}
		}
		return res;
	}
};
// 2. 把数组放入map中，然后遍历数组，如果当前数-1不在map中，也就是当前数是序列第1个数，则自增判断连续序列，更新res，遍历结束后返回res即可。
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		map<int, int> m;
		for (auto num : nums) {
			m[num]++;
		}
		int res = 0;
		for (auto num : nums) {
			if (m.find(num - 1) == m.end()) {
				int i = num + 1;
				while (m.find(i)!=m.end())
				{
					i++;
				}
				if (i - num > res) {
					res = i - num;
				}
			}
		}
		return res;
	}
};