// 利用四平方和定理推论求值，满足四平方和定理的数，必定满足 n=4^a(8b+7)
class Solution {
public:
	int numSquares(int n) {
		if (n < 0) return 0;
		if (n < 2) return 1;
		int num = n;
		while (num % 4 == 0)
		{
			num /= 4;
		}
		if (num % 8 == 7)
		{
			return 4;
		}
		int left = 0, right = sqrt(num);
		if (right*right == num) {
			return 1;
		}
		while (left<=right)
		{
			long long sum = (long long)left*left + (long long)right*right;
			if (sum > num) {
				right--;
			}
			else if (sum<num) {
				left++;
			}
			else {
				return 2;
			}
		}
		return 3;
	}
};
// 