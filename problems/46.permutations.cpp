// 使用nextPermutation实现
class Solution {
	bool nextPermutation(vector<int>& nums) {
		int n = nums.size();
		int i;
		for (i = n - 2; i >= 0; i--)
		{
			if (nums[i + 1] > nums[i])
				break;
		}
		if (i < 0) {
			return false;
		}
		int j, m = INT_MAX;
		for (int k = i + 1; k < n; k++) {
			if (nums[k] > nums[i] && m>nums[k]) {
				m = nums[k];
				j = k;
			}
		}
		swap(nums[i], nums[j]);
		sort(nums.begin() + i + 1, nums.end());
		return true;
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		bool t = true;
		do
		{
			res.push_back(nums);
			t = nextPermutation(nums);
		} while (t);
		return res;
	}
};
// 回溯算法实现
class Solution {
	void backTrack(vector<vector<int>>& list, vector<int>& nums, int index) {
		if (index == nums.size()) {
			list.push_back(nums);
			return;
		}
		for (int i = index; i < nums.size(); i++)
		{
			swap(nums[index], nums[i]);
			backTrack(list, nums, index + 1);
			swap(nums[index], nums[i]);
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> res;
		backTrack(res, nums, 0);
		return res;
	}
};