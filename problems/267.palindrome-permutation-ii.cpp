// 用了全排序
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
	vector<vector<int>> permute(vector<int>& nums) {
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
public:
	vector<string> generatePalindromes(string s) {
		unordered_map<char, int> map;
		for (auto ch : s) {
			map[ch]++;
		}
		int oddNum = 0;
		for (auto iter : map) {
			if (iter.second % 2)
				oddNum++;
		}
		vector<string> res;
		if (oddNum > 1) {
			return res;
		}
		char mid;
		vector<int> list;
		for (auto iter : map) {
			if (iter.second % 2) {
				mid = iter.first;
			}
			int n = iter.second / 2;
			for (int i = 0; i < n; i++)
			{
				list.push_back(iter.first);
			}
		}
		vector<vector<int>> orgRes = permute(list);
		string str;
		for (size_t i = 0; i < orgRes.size(); i++)
		{
			str = "";
			for (int j = 0; j < orgRes[i].size(); j++)
			{
				str += orgRes[i][j];
			}
			if (oddNum == 1) {
				str += mid;
			}
			for (int j = orgRes[i].size()-1; j >= 0; j--)
			{
				str += orgRes[i][j];
			}
			res.push_back(str);
		}
		return res;
	}
};