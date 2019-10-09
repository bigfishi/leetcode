// 简单 双指针，类似350，需要注意不能输出相同元素
class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		int i = 0, j = 0;
		vector<int> res;
		while (i<nums1.size() && j<nums2.size())
		{
			if (nums1[i] == nums2[j]) {
				res.push_back(nums1[i]);
				while (i<nums1.size() && nums1[i]==res.back())
				{
					i++;
				}
				while (j<nums2.size() && nums2[j]==res.back())
				{
					j++;
				}
			}
			else if (nums1[i]>nums2[j]) {
				j++;
			}
			else {
				i++;
			}
		}
		return res;
	}
};