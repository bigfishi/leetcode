class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> map;
		for (size_t i = 0; i < nums.size(); i++)
		{
			if (map.count(target - nums[i])) {
				return vector<int>{static_cast<int>(i), map[target - nums[i]]};
			}
			map[nums[i]] = i;
		}
		return vector<int>();
	}
};