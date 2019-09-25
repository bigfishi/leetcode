// 最初的提交，错误，1,5,1 结果应该是 5,1,1 我的结果是 1,1,5
// 从后先前找到一个比后面元素小的元素，从该元素后面找到比该元素大的最小元素，交换，然后将该元素后面的元素排序。如果找不到该元素，则按升序重新排序列表
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size(), i;
		for (i = n-2; i >= 0; i--)
		{
			if (nums[i + 1] > nums[i])
				break;
		}
		if (i < 0) {	 // 完全逆序
			int left = 0, right = n - 1;
			while (left<right)
			{
				swap(nums[left], nums[right]);
				left++;
				right--;
			}
			return;
		}
		// 到后面比当前数大的最小数
		int j, min = INT_MAX;
		for (int k = i + 1; k < n; k++) {
			if (nums[k] >= nums[i] && min>nums[k]) {
				min = nums[k];
				j = k;
			}
		}
		swap(nums[i], nums[j]);
		sort(nums.begin() + i + 1, nums.end());
		return;
	}
};
// 修改
class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size(), i;
		for (i = n-2; i >= 0; i--)
		{
			if (nums[i + 1] > nums[i])
				break;
		}
		if (i < 0) {	 // 完全逆序
			int left = 0, right = n - 1;
			while (left<right)
			{
				swap(nums[left], nums[right]);
				left++;
				right--;
			}
			return;
		}
		// 到后面比当前数大的最小数
		int j, min = INT_MAX;
		for (int k = i + 1; k < n; k++) {
			if (nums[k] > nums[i] && min>nums[k]) {
				min = nums[k];
				j = k;
			}
		}
		swap(nums[i], nums[j]);
		sort(nums.begin() + i + 1, nums.end());
		return;
	}
};