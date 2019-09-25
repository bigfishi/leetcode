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
	vector<vector<int>> permuteUnique(vector<int>& nums) {
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