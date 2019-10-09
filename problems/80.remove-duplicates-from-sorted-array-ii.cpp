// 中等 类似26，增加一个变量记录是否已有重复数
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int n = nums.size();
		if (n < 3) return n;
		int count = 1;
		bool isDup = false;
		for (int i = 1; i < n; i++) {
			if (nums[i] != nums[i - 1]) {
				count++;
				isDup = false;
			}
			else if (!isDup) {
				isDup = true;
				count++;
			}
		}
		int index = 1, pre = nums[0];
		int i = 1;
		isDup = false;
		while (i < n)
		{
			while (i < n && isDup && nums[i] == pre)
				i++;
			if (i < n) {
				if (nums[i] == pre)
					isDup = true;
				else
					isDup = false;
				pre = nums[i];
				nums[index++] = nums[i++];
			}
		}
		return count;
	}
};