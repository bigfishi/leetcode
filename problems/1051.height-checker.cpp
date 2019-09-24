class Solution {
public:
	int heightChecker(vector<int>& heights) {
		int res = 0;
		vector<int> copy(heights);
		sort(copy.begin(), copy.end());
		for (size_t i = 0; i < copy.size(); i++)
		{
			if (copy[i] != heights[i]) {
				res++;
			}
		}
		return res;
	}
};