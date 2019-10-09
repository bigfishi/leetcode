// 简单
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int n = nums.size();
		int zn = 0;
		for (auto num : nums)
			if (!num) zn++;
		int index = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i])
				nums[index++] = nums[i];
		}
		for (int i = n - zn; i < n; i++)
			nums[i] = 0;
	}
};