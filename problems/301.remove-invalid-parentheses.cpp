// 困难，用dfs方法 第一次提交错误，因为传入dfs函数的临时遍历以引用方式传递，递归的时候没有创建新的字符串
// 
class Solution {
	void dfs(string& s, set<string>& set, string& t, int index, int bnum, int& size) {
		if (index >= s.size()) {
			if (bnum == 0 && t.size()>=size) {
				size = t.size();
				set.insert(t);
			}
			return;
		}
		if (s[index] != '(' && s[index] != ')') {
			t += s[index];
			dfs(s, set, t, index + 1, bnum, size);
		}
		else if (s[index] == '(') {
			string t2 = t;
			if (index + 1 + bnum < s.size()) {
				t += s[index];
				dfs(s, set, t, index + 1, bnum + 1, size);
			}
			dfs(s, set, t2, index + 1, bnum, size);
		}
		else {
			string t2 = t;
			if (bnum > 0) {
				t += s[index];
				dfs(s, set, t, index + 1, bnum - 1, size);
				t.pop_back();
			}
			dfs(s, set, t2, index + 1, bnum, size);
		}
	}
public:
	vector<string> removeInvalidParentheses(string s) {
		string t = "";
		int index = 0;
		int bnum = 0;
		int size = 0;
		set<string> set;
		dfs(s, set, t, index, bnum, size);
		vector<string> list(set.begin(), set.end());
		vector<string> res;
		size = 0;
		for (size_t i = 0; i < list.size(); i++)
		{
			if (list[i].size()>size) {
				size = list[i].size();
			}
		}
		for (size_t i = 0; i < list.size(); i++)
		{
			if (list[i].size() == size) {
				res.push_back(list[i]);
			}
		}
		return res;
	}
};