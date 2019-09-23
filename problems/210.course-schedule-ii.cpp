// 在207的基础上修改，不要注意的是，如果无法完成拓扑遍历，返回空列表
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
			if (in[i] == 0)
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
		if (list.size() == numCourses) {
			reverse(list.begin(), list.end());
			return list;
		}
		else {
			return {};
		}
	}
};