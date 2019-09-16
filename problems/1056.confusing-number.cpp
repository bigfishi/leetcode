class Solution {
public:
	bool confusingNumber(int N) {
		string str = to_string(N);
		string str2(str);
		reverse(str2.begin(), str2.end());
		for (size_t i = 0; i < str2.size(); i++)
		{
			if (str2[i] == '6') {
				str2[i] = '9';
			}
			else if (str2[i] == '9') {
				str2[i] = '6';
			}
			else if (str2[i] == '2' || str2[i] == '3' || str2[i] == '4' || str2[i] == '5' || str2[i] == '7') {
				return false;
			}
		}
		return str2 != str;
	}
};