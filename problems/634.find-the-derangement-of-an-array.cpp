// 递推，得到公式 f(n)=(n-1)*(f(n-1)+f(n-2))*
// 长度为n的错乱排序序列，不看第n个数，其他n-1个数组成错乱排序序列，n可与任意一个数交换，得到算式(n-1)*(f(n-1))*
// 需要了解到这种思路不能覆盖所有情况，比如1位置永远不可能为1，而如果排除1和n，其他n-2个数组成错乱序列之后，1和n位置交换，也是错乱序列，得到算式(n-1)*(f(n-2))* 
// 两个算式覆盖了所有情况，故公式为 f(n)=(n-1)*(f(n-1)+f(n-2))*
class Solution {
	const int INF = 1000000007;
public:
	int findDerangement(int n) {
		if (n < 2) return 0;
		if (n == 2) return 1;
		int f1 = 0, f2 = 1;
		int res = 0;
		for (int i = 3; i <= n; i++) {
			res = (long long)(n - 1)*(f1 + f2)%INF;
			f1 = f2;
			f2 = res;
		}
		return res;
	}
};