class Solution {
	vector<string> res;
	inline void swap(string& s, int i, int j) {
		char ch = s[i];
		s[i] = s[j];
		s[j] = ch;
	}
	void allRange(string& s, int start) {
		int n = s.size();
		if (start == n) {
			res.push_back(s);
			return;
		}
		for (size_t i = start; i < n; i++)
		{
			swap(s, start, i);
			allRange(s, start+1);
			swap(s, start, i);
		}
	}
	bool canSwap(string& s, int i, int j) {
		for (size_t index = i; index < j; index++)
		{
			if (s[index] == s[j]) {
				return false;
			}
		}
		return true;
	}
	// abb
	// bab
	// bba
	void allRangeWithDuplication(string& s, int start) {
		int n = s.size();
		if (start == n) {
			res.push_back(s);
			return;
		}
		for (size_t i = start; i < n; i++)
		{
			if (canSwap(s, start, i)) {
				swap(s, start, i);
				allRangeWithDuplication(s, start+1);
				swap(s, start, i);
			}
		}
	}
public:
	// 排列组合公式
	// A(n,m) = n!/(n-m)! = n*(n-1)...1/(n-m)/(n-m-1).../1 = n*(n-1)...(n-m+1)
	// C(n,m) = A(n,m)/A(m,m)=n!/(n-m)!/m!
	// C(n,m) = C(n,n-m)=A(n,n-m)/A(n-m,n-m)=n!/m!/(n-m)!
	vector<string> permutation(string& s) {
		res.clear();
		allRange(s, 0);
		return res;
	}
	vector<string> permutationWithDuplication(string& s) {
		res.clear();
		allRangeWithDuplication(s, 0);
		return res;
	}
	vector<string> combination(string& s) {
		res.clear();
		int n = s.size();
		int b = 1 << n;
		for (size_t i = 1; i < b; i++)
		{
			string t = "";
			for (size_t j = 0; j < n; j++)
			{
				if (i&(1 << j)) {
					t += s[j];
				}
			}
			res.push_back(t);
		}
		return res;
	}
};