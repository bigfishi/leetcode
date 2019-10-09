// 中等 没思路。
// 先排序，然后从中间分开，排在前面的数组和排在后面的数组都从后向前，依次取数放入新数组，最后返回新数组
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		if (nums.size() < 3) return;
		int mid = (nums.size()+1) / 2;
		vector<int> res;
		int t = nums.size() - 1;
        int t2 = mid-1;
		for (int i = 0; i < mid; i++) {
            if (t2<-1) break;
			res.push_back(nums[t2--]);
			if (t < mid) break;
			res.push_back(nums[t--]);
		}
		nums = res;
	}
};
// 参考 https://leetcode-cn.com/problems/wiggle-sort-ii/solution/reindexing-by-buptlee/
// 完全没看懂
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		if (nums.size() == 0) return;
		int n = nums.size();
		nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
		int mid = *(nums.begin() + n / 2);
		int i = 0, j = 0, k = n - 1;
		#define A(i) nums[(1+2*(i))%(n|1)]
		while (j<=k)
		{
			if (A(j) > mid) {
				swap(A(i++), A(j++));
			}
			else if (A(j) < mid) {
				swap(A(k--), A(j));
			}
			else {
				j++;
			}
		}
	}
};