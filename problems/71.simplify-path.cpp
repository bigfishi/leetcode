class Solution {
public:
	string simplifyPath(string path) {
		stack<string> st;
		int pos = 0;
		while (pos<path.size())
		{
			string::size_type tPos = path.find('/', pos);
			if (tPos == string::npos) {
				tPos = path.size();
			}
			if (tPos > pos) {
				string sub = path.substr(pos, tPos - pos);
				if (sub == ".") {

				}
				else if (sub == "..") {
					if (st.size())
						st.pop();
				}
				else {
					st.push(sub);
				}
			}
			pos = tPos+1;
		}
		vector<string> list;
		while (st.size())
		{
			list.push_back(st.top());
			st.pop();
		}
		string res = "";
		for (auto iter = list.rbegin(); iter != list.rend(); iter++) {
			res += "/" + *iter;
		}
		if (res.size() == 0)
			res = "/";
		return res;
	}
};
