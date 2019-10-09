// 简单 排序，然后用2个索引分别遍历数组，相同放入结果，不同将小的一方的数组索引增大，循环结束可以找到所有交集
class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		vector<int> res;
		int i = 0, j = 0;
		while (i<nums1.size() && j<nums2.size())
		{
			if (nums1[i] == nums2[j]) {
				res.push_back(nums1[i]);
				i++, j++;
			}
			else if (nums1[i] > nums2[j]) {
				j++;
			}
			else {
				i++;
			}
		}
		return res;
	}
};