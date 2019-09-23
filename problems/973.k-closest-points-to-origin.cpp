// 按规则排序排序的比较函数即可
class Solution {
	static bool comp(const vector<int>& a, const vector<int>& b) {
		return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
	}
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		sort(points.begin(), points.end(), comp);
		vector<vector<int>> res(points.begin(), points.begin() + K);
		return res;
	}
};