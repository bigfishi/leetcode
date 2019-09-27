class Solution {
public:
	bool isOneEditDistance(string s, string t) {
		if (s.size() + 1 == t.size()) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != t[i]) {
					string s2;
					if (!i) s2 = t[i] + s;
					else s2 = s.substr(0, i) + t[i] + s.substr(i);
					if (s2 == t) return true; else return false;
				}
			}
			return true;
		}
		else if (s.size() == t.size() + 1) {
			for (int i = 0; i < t.size(); i++) {
				if (s[i] != t[i]) {
					string s2;
					if (!i) s2 = s.substr(i + 1);
					else s2 = s.substr(0, i) + s.substr(i + 1);
					if (s2 == t) return true; else return false;
				}
			}
			return true;
		}
		else if (s.size() == t.size()) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != t[i]) {
					string s2 = s;
					s2[i] = t[i];
					if (s2 == t) return true; else return false;
				}
			}
			return false;
		}
		return false;
	}
};
