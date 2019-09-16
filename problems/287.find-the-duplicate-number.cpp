// 快慢指针 弗洛伊德的乌龟和兔子
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int ih = nums[0];
		int it = nums[0];
		do
		{
			ih = nums[nums[ih]];
			it = nums[it];
		} while (ih!=it);
		int i = nums[0];
		while (i!=it)
		{
			i = nums[i];
			it = nums[it];
		}
		return it;
	}
};
// 二分查找
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left<right)
		{
			mid = (left + right) >> 1;
			int count = 0;
			for (size_t i = 0; i < nums.size(); i++)
			{
				if (nums[i] <= mid) {
					count++;
				}
			}
			if (count > mid) {
				right = mid;
			}
			else {
				left = mid + 1;
			}
		}
		return left;
	}
};