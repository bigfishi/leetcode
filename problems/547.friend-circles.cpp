// 中等 并查集，带count，初始化时count为最大，每次union都自减
class Solution {
	vector<int> list;
	vector<int> rank;
	int count;
	void initCircle(int n) {
		for (int i = 0; i < n; i++) {
			list.push_back(i);
			rank.push_back(0);
		}
		count = n;
	}
	int find(int i) {
		if (list[i] != i) {
			list[i] = find(list[i]);
		}
		return list[i];
	}
	void unionCircle(int i, int j) {
		int x = find(i);
		int y = find(j);
		if (x == y) return;
		count--;
		if (rank[x] < rank[y]) {
			list[x] = y;
		}
		else if (rank[x]>rank[y]) {
			list[y] = x;
		}
		else {
			list[x] = y;
			rank[y]++;
		}
	}
public:
	int findCircleNum(vector<vector<int>>& M) {
		int n = M.size();
		initCircle(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (M[i][j] == 1) {
					unionCircle(i, j);
				}
			}
		}
		return count;
	}
};