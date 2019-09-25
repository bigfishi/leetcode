// 简单，一次通过，不过花了1:57，快的有1分钟，慢的也是1:30左右
class Solution {
public:
	int game(vector<int>& guess, vector<int>& answer) {
		int res = 0;
		for (size_t i = 0; i < guess.size(); i++)
		{
			if (guess[i] == answer[i]) {
				res++;
			}
		}
		return res;
	}
};