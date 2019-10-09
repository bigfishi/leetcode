// 交并集
class UnionFind2 {
	vector<int> parent;
	vector<int> rank;
	int count;
public:
	UnionFind2(int N) {
		count = 0;
		for (int i = 0; i < N; i++) {
			parent.push_back(-1);
			rank.push_back(0);
		}
	}
	bool isValid(int i) const {
		return parent[i] >= 0;
	}
	void setParent(int i) {
		parent[i] = i;
		++count;
	}
	bool canFind(int i) {
		if (parent[i] == -1) return false;
		return true;
	}
	int find(int i) {	// path compression
		if (parent[i] != i)
			parent[i] = find(parent[i]);
		return parent[i];
	}

	void Union(int x, int y) { // union with rank
		int rootx = find(x);
		int rooty = find(y);
		if (rootx != rooty) {
			if (rank[rootx] > rank[rooty])
				parent[rooty] = rootx;
			else if (rank[rootx] < rank[rooty])
				parent[rootx] = rooty;
			else {
				parent[rooty] = rootx;
				++rank[rootx];
			}
			--count;
		}
	}

	int getCount() const {
		return count;
	}
};

class Solution {
public:
	vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
		vector<vector<int>> delta{ { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
		vector<int> res;
		UnionFind2 uf(m*n);
		for (auto& pos : positions) {
			int r = pos[0], c = pos[1];
			int t = r*n + c;
			if (!uf.canFind(t)) {
				// check pos's neighbours to see if they are in the existing islands or not
				vector<int> overlap;	// how many existing islands overlap with 'pos'
				for (int i = 0; i < 4; i++) {
					int x = r + delta[i][0];
					int y = c + delta[i][1];
					int t = x*n + y;
					if (x >= 0 && x < m && y >= 0 && y < n && uf.isValid(t))
						overlap.push_back(t);
				}
				uf.setParent(t);
				for (auto i : overlap) {
					uf.Union(i, t);
				}
			}
			res.push_back(uf.getCount());
		}
		return res;
	}
};