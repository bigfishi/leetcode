// 中等，方法类似于169的进阶方法，该方法学名叫摩尔投票法。我自己没想出来，参考别人的方法
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		// 摩尔投票法
		int x = 0, y = 0, cx = 0, cy = 0;
		for (auto num : nums) {
			if ((cx == 0 || x == num) && num != y) {
				x = num;
				cx++;
			}
			else if (cy == 0 || y == num) {
				y = num;
				cy++;
			}
			else {
				cx--;
				cy--;
			}
		}
		int count = 0;
		for (auto num : nums) {
			if (x == num) count++;
		}
		vector<int> res;
		if (count > nums.size() / 3) res.push_back(x);
		if (x == y) return res;
		count = 0;
		for (auto num : nums) {
			if (y == num) count++;
		}
		if (count > nums.size() / 3) res.push_back(y);
		return res;
	}
};