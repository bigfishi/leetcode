// 简单
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int n = nums.size();
		int count = 0;
		for (int i = 0; i < n; i++)
			if (nums[i] == val)
				count++;
		int index = 0;
		for (int i = 0; i < n; i++) {
			if (nums[i] != val) {
				nums[index++] = nums[i];
			}
		}
		for (int i = n - count; i < n; i++) {
			nums[i] = val;
		}
		return n - count;
	}
};