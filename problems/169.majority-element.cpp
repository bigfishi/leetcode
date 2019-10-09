// 简单 最简单的方法是通过哈希表做统计
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		unordered_map<int, int> map;
		int n = nums.size();
		for (auto num : nums) {
			map[num]++;
			if (map[num] > n / 2) {
				return num;
			}
		}
		return 0;
	}
};
// 进阶方法是设定key为0，count为1，从1开始遍历数组，val相同则count自增，反之则自减，当count为-1时，重置count为1，将当前i赋值给key，循环结束nums[key]即为众数
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int key = 0, count = 1;
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] == nums[key]) {
				count++;
			}
			else {
				count--;
				if (count == -1) {
					count = 1;
					key = i;
				}
			}
		}
		return nums[key];
	}
};