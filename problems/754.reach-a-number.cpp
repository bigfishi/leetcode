// 题目说是简单的，但是按简单思路做出来的不是正确值，参考了[Python超级简洁的解法](https://leetcode-cn.com/problems/reach-a-number/solution/pythonchao-ji-jian-ji-de-jie-fa-by-zhengkang/)
class Solution {
public:
	int reachNumber(int target) {
		target = abs(target);
		int i = 0;
		int p = 0;
		while (p < target || (p + target) % 2 != 0) {
			i += 1;
			p += i;
		}
		return i;
	}
};
