// 中等 用前缀和，时间复杂度为O(N^2)。
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			nums[i] += nums[i - 1];
		}
		nums.insert(nums.begin(), 0);
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n+1; j++) {
				if (nums[j] - nums[i]==k)
					res++;
			}
		}
		return res;
	}
};
// 累加，不用前缀和
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int n = nums.size();
		int res = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = i; j < n; j++) {
				sum += nums[j];
				if (sum == k)
					res++;
			}
		}
		return res;
	}
};
// 也有空间换时间的方法，用哈希表，每次都累加，如果哈希表中有k-sum，则次数加对应次数
class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		map<int, int> m;
		m[0] = 1;
		int sum = 0, res = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			res += m[sum - k];
			m[sum]++;
		}
		return res;
	}
};