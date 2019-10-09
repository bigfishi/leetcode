// 中等，参考了别人的答案
// 对于确定长度的数，各个位数不同的数字，第1位可以是1-9中任意1个，共9个可能，第2位可以是0-9除了第1位之外的任意1个，共9个可能，第3位8个可能，以此类推
// 需要注意的是超过10位的数字不满足条件。结果是0-n每种长度相加。
class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (n == 0) return 1;
		int res = 1;
		for (int i = 1; i <= n && i<=10; i++) {
			int cur = 9;
			for (int j = 9, count = 1; count < i; j--, count++) {
				cur *= j;
			}
			res += cur;
		}
		return res;
	}
};