// 贪心算法
class Solution {
public:
	vector<int> findPermutation(string s) {
		int n = s.size();
		vector<int> res(n,0);
		for (int i = 0; i <= n; i++) {
			res[i] = i + 1;
		}
		int index = 0;
		while (index<n)
		{
			int num = 0;
			while (index+num<n && s[index+num]=='D')
			{
				num++;
			}
			if (num)
				reverse(res.begin() + index, res.begin() + index + num + 1);
			index += num + 1;
		}
		return res;
	}
};