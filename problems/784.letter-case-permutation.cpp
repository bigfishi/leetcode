// dfs方法
class Solution {
	void dfs(vector<string>& list, string& S, int index) {
		int n = S.size();
		if (index == n) {
			list.push_back(S);
			return;
		}
		int nextIndex = n;
		for (size_t i = index+1; i < n; i++)
		{
			if (S[i] >= 'A'&&S[i] <= 'Z' || S[i] >= 'a'&&S[i] <= 'z') {
				nextIndex = i;
				break;
			}
		}
		if (S[index] >= 'A'&&S[index] <= 'Z') {
			dfs(list, S, nextIndex);
			S[index] += 32;
			dfs(list, S, nextIndex);
		}
		else if (S[index] >= 'a'&&S[index] <= 'z') {
			dfs(list, S, nextIndex);
			S[index] -= 32;
			dfs(list, S, nextIndex);
		}
		else {
			dfs(list, S, nextIndex);
		}
	}
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> res;
		dfs(res, S, 0);
		return res;
	}
};
// 位运算
class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> res;
		int b = 0;
		for (size_t i = 0; i < S.size(); i++)
		{
			if (isalpha(S[i]))
				b++;
		}
		transform(S.begin(), S.end(), S.begin(), ::tolower);
		int t = 1 << b;
		for (size_t i = 0; i < t; i++)
		{
			int index = 0;
			for (size_t j = 0; j < S.size(); j++)
			{
				if (isalpha(S[j])) {
					if (i&(1 << index)) {
						S[j] = toupper(S[j]);
					}
					else {
						S[j] = tolower(S[j]);
					}
					index++;
				}
			}
			res.push_back(S);
		}
		return res;
	}
};