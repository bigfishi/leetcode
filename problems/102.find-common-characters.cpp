// 简单，用HashMap
class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		unordered_map<char, int> map;
		for (int i = 0; i < A[0].size(); i++)
			map[A[0][i]]++;
		unordered_map<char, int> map2;
		for (int i = 1; i < A.size(); i++) {
			map2.clear();
			for (auto item : map) {
				map2[item.first] = item.second;
			}
			for (int j = 0; j < A[i].size(); j++) {
				if (map2.find(A[i][j])!=map2.end() && map2[A[i][j]]>0) {
					map2[A[i][j]]--;
				}
			}
			for (auto item : map) {
				map[item.first] = item.second - map2[item.first];
			}
		}
		vector<string> res;
		for (auto item : map) {
			for (int i = 0; i < item.second;i++) {
				string s = "";
				s += item.first;
				res.push_back(s);
			}
		}
		return res;
	}
};
// 看了别人的代码，发现他们用数组实现，对于这种只有小写字母出现的字符串，可以用一个char[26]数组实现。
class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		char store[2][26];
		memset(store, 0, sizeof(store));
		for (int i = 0; i < A[0].size(); i++) {
			store[0][A[0][i] - 'a']++;
		}
		for (int i = 1; i < A.size(); i++) {
			for (int j = 0; j < A[i].size(); j++) {
				store[1][A[i][j] - 'a']++;
			}
			for (int j = 0; j < 26; j++) {
				store[0][j] = min(store[0][j], store[1][j]);
				store[1][j] = 0;
			}
		}
		vector<string> res;
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < store[0][i]; j++) {
				string s = "";
				s += i + 'a';
				res.push_back(s);
			}
		}
		return res;
	}
};