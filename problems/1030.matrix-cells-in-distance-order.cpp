class Solution {
public:
	vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
		vector<vector<int>> list;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				list.push_back({ i, j });
			}
		}
		sort(list.begin(), list.end(), [&](const vector<int>& a, const vector<int>& b) {
			int disA = abs(a[0] - r0) + abs(a[1] - c0);
			int disB = abs(b[0] - r0) + abs(b[1] - c0);
			return disA < disB;
		});
		return list;
	}
};