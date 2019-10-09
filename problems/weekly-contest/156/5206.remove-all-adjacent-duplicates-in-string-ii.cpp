// 刚开始没思路，觉得常规方法不行，然后硬着头皮做，做着做着，就ok了。这题难点在于删除子串之后如何处理，这里我将索引减去k
class Solution {
public:
	string removeDuplicates(string s, int k) {
		int i = 0;
		while (i<s.size())
		{
			int num = 1;
			if (num<k)
			{
				for (int j = i + 1; j < s.size(); j++) {
					if (s[i] == s[j] && num < k)
						num++;
					else
						break;
				}
			}
			if (num >= k) {
				s = s.substr(0, i) + s.substr(i + k);
				i = max(-1, i - k);
			}
			i++;
		}
		return s;
	}
};