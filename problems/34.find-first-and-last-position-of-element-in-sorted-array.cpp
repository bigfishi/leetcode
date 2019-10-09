// 中等 二分查找到元素，然后向左向右找
class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int n = nums.size();
		vector<int> res(2, -1);
		if (n == 0) return res;
		int l = 0, r = n - 1, mid;
		while (l<=r)
		{
			mid = (l + r) / 2;
			if (nums[mid] == target) {
				break;
			}
			else if (nums[mid] > target) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		if (nums[mid] != target) return res;
		l = max(0, mid - 1), r = min(n - 1, mid + 1);
		while (l>=0 && nums[l]==target)
		{
			l--;
		}
		while (r<=n-1 && nums[r]==target)
		{
			r++;
		}
		res[0] = l + 1;
		res[1] = r - 1;
		return res;
	}
};