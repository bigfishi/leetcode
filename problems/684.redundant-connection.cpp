// 中等 并查集，遍历数组，如果不需要union，则将元素加入备选数组，返回备选数组最后一个元素
class Solution {
	vector<int> parent;
	vector<int> rank;
	void init(int n) {
		for (int i = 0; i <= n; i++) {
			parent.push_back(i);
			rank.push_back(0);
		}
	}
	int find(int i) {
		if (parent[i] != i)
			parent[i] = find(parent[i]);
		return parent[i];
	}
	bool unionFind(int i, int j) {
		int x = find(i);
		int y = find(j);
		if (x == y) return false;
		if (rank[x] > rank[y])
			parent[y] = x;
		else if (rank[x] < rank[y])
			parent[x] = y;
		else {
			parent[x] = y;
			rank[y]++;
		}
		return true;
	}
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		int n = edges.size();
		init(n);
		vector<vector<int>> resList;
		for (int i = 0; i < n; i++) {
			if (!unionFind(edges[i][0], edges[i][1])) {
				resList.push_back(edges[i]);
			}
		}
		return resList.back();
	}
};