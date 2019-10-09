// 全排列的中介数 算出中介数，然后根据中介数获取排列
// 1. 求阶乘，第1位是0!，第2位是1!，第n位是(n-1)!
// 2. 获取了某位的中介数，求该位置的数，中介数是从1开始第t个未使用的数
class Solution {
public:
	string getPermutation(int n, int k) {
		vector<int> nums(n, 1);
		int cur = 1;
		for (int i = 1; i < n; i++) {
			cur *= i;
			nums[n - i - 1] = cur;
		}
		unordered_map<int, bool> map;
		string res = "";
		for (int i = 0; i < n; i++) {
			int t = 0;
			while (k>nums[i])
			{
				k -= nums[i];
				t++;
			}
			int m = t;
			for (int j = 0; j < n; j++) {
				if (!map[j])
				{
					if (t == 0) {
						m = j + 1;
						map[j] = true;
						break;
					}
					t--;
				}
			}
			res += '0' + m;
		}
		return res;
	}
};