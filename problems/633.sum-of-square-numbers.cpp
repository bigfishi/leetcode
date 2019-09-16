// 二分法计算平方根，再二分法查找两个完全平方数
class Solution {
public:
	bool judgeSquareSum(int c) {
		if (c < 0) return false;
		int left = 0, right = sqrt(c);
		while (left<=right)
		{
			long long num = (long long)left*left + (long long)right*right;
			if (num > c) {
				right--;
			}
			else if (num < c) {
				left++;
			}
			else {
				return true;
			}
		}
		return false;
	}
private:
	int sqrt(int num) {
		if (num == 1 || num == 0)
			return num;
		int left = 0, right = num >> 1;
		int mid;
		while (left<=right)
		{
			mid = (left + right) >> 1;
			long long ji = (long long)mid*mid;
			if (ji == num)
				break;
			else if (ji>num) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return mid;
	}
};