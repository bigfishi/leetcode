// 简单，统计不重复个数，然后用i遍历数组，用index作为不重复数索引，遍历到不重复数，根据index放入相应位置。
// 需要注意在while循环中，循环变量不稳定自增，需要在过程中检测是否越界
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n < 2) return n;
		int count = 1;
		for (int i = 1; i < n; i++)
			if (nums[i] != nums[i - 1])
				count++;
		int index = 1;
		int pre = nums[0];
		int i = 1;
		while (i < n)
		{
			while (i<n && nums[i] == pre) {
				i++;
			}
			if (i < n) {
				pre = nums[i];
				nums[index++] = nums[i++];
			}
		}
		return count;
	}
};