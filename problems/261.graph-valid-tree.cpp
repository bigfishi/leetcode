// 判断无向图是否有环，另外还需要节点之间都联通
class Solution {
	enum {
		VISIT_STATE_NO = 0,
		VISIT_STATE_VISITING,
		VISIT_STATE_END
	};
	void dfs(int index, vector<vector<int>>& graph, vector<int>& visited, vector<int>& father, bool& noCircle) {
		if (!noCircle) return;
		if (visited[index] == VISIT_STATE_END) return;
		visited[index] = VISIT_STATE_VISITING;
		for (size_t i = 0; i < graph.size(); i++)
		{
			if (index != i && graph[index][i] == 1) {
				if (visited[i] == VISIT_STATE_VISITING && father[index] != i) {
					noCircle = false;
					return;
				}
				else {
					if (visited[i] == 0) {
						father[i] = index;
						dfs(i, graph, visited, father, noCircle);
					}
				}
			}
		}
		visited[index] = VISIT_STATE_END;
	}
public:
	bool validTree(int n, vector<vector<int>>& edges) {
		vector<int> visited, father;
		for (size_t i = 0; i < n; i++)
		{
			visited.push_back(VISIT_STATE_NO);
			father.push_back(-1);
		}
		vector<vector<int>> graph(n);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				graph[i].push_back(0);
			}
		}
		for (size_t i = 0; i < edges.size(); i++)
		{
			graph[edges[i][0]][edges[i][1]] = 1;
			graph[edges[i][1]][edges[i][0]] = 1;
		}
		bool res = true;
		dfs(0, graph, visited, father, res);
		if (res) {
			for (size_t i = 0; i < visited.size(); i++)
			{
				if (visited[i] != VISIT_STATE_END) {
					res = false;
					break;
				}
			}
		}
		return res;
	}
};