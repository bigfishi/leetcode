class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		string str = to_string(x);
		int len = str.size();
		int left = 0, right = len - 1;
		while (left < right) {
			if (str[left] != str[right]) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};