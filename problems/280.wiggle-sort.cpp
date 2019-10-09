// 中等 排序，然后两两交换
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 1; i < n-1; i+=2) {
			swap(nums[i], nums[i + 1]);
		}
	}
};
// 用布尔值
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		bool less = true;
		int n = nums.size();
		for (int i = 0; i < n-1; i++) {
			if (less) {
				if (nums[i] > nums[i + 1]) {
					swap(nums[i], nums[i + 1]);
				}
			}
			else {
				if (nums[i] < nums[i + 1]) {
					swap(nums[i], nums[i + 1]);
				}
			}
			less = !less;
		}
	}
};