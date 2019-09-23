// 20分钟 图的表示方法和拓扑排序，这些知识点比较生疏，不过总体挺简单，是拓扑排序的简单应用。
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		vector<vector<int>> graph(numCourses);
		vector<int> in(numCourses, 0);
		for (size_t i = 0; i < graph.size(); i++)
		{
			for (size_t j = 0; j < numCourses; j++)
			{
				graph[i].push_back(0);
			}
		}
		for (size_t i = 0; i < prerequisites.size(); i++)
		{
			graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
			in[prerequisites[i][1]]++;
		}
		queue<int> q;
		for (size_t i = 0; i < in.size(); i++)
		{
			if (in[i]==0)
				q.push(i);
		}
		vector<int> list;
		while (q.size())
		{
			int i = q.front();
			q.pop();
			list.push_back(i);
			for (size_t j = 0; j < graph.size(); j++)
			{
				if (graph[i][j]) {
					in[j]--;
					graph[i][j] = 0;
					if (in[j] == 0)
						q.push(j);
				}
			}
		}
		bool res = (list.size() == numCourses);
		return res;
	}
};