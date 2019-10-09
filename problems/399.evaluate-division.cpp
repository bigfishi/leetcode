// 并查集
struct ValueNode {
	double value;
	ValueNode* parent;
	ValueNode() : parent(this) {}
	ValueNode(double val) : value(val), parent(this) {}
};
class Solution {
	unordered_map<string, ValueNode*> m;
	ValueNode* find(ValueNode* node) {
		if (node->parent != node) {
			node->parent = find(node->parent);
		}
		return node->parent;
	}
	void Union(ValueNode* n1, ValueNode* n2, double val) {
		ValueNode* p1 = find(n1);
		ValueNode* p2 = find(n2);
		double ratio = n2->value*val / n1->value;
		for (auto& it : m)
			if (find(it.second) == p1)
				it.second->value *= ratio;
		p1->parent = p2;
	}
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		for (int i = 0; i < equations.size(); i++) {
			string& s1 = equations[i][0];
			string& s2 = equations[i][1];
			if (m.find(s1) == m.end())
				m[s1] = new ValueNode(values[i]);
			if (m.find(s2) == m.end())
				m[s2] = new ValueNode(1.0);
			Union(m[s1], m[s2], values[i]);
		}
		vector<double> res;
		for (int i = 0; i < queries.size(); i++) {
			string& s1 = queries[i][0];
			string& s2 = queries[i][1];
			if (m.find(s1) == m.end() || m.find(s2) == m.end() || find(m[s1]) != find(m[s2])) {
				res.push_back(-1);
			}
			else {
				res.push_back(m[s1]->value / m[s2]->value);
			}
		}
		return res;
	}
};

