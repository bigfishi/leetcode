// 中等 刚开始比较在意平均数计算是否会越界，参考了别人的发现直接相加，因为是double，不用担心越界
class Solution {
public:
	vector<double> sampleStats(vector<int>& count) {
		int n = count.size();
		vector<double> res(5, 0);
		for (int i = 0; i < n; i++)
			if (count[i]) {
				res[0] = i;
				break;
			}
		for (int i = n - 1; i >= 0; i--) {
			if (count[i]) {
				res[1] = i;
				break;
			}
		}
		double avg = 0;
		int c = 0;
		for (int i = res[0]; i <= res[1]; i++) {
			avg += i*count[i];
			c += count[i];
		}
		avg = avg / c;
		res[2] = avg;
		int sum = accumulate(count.begin(), count.end(), 0);
		bool odd = false;
		int mid = sum / 2;
		int cur = 0;
		int left = -1, right = -1;
		for (int i = res[0]; i <= res[1]; i++) {
			cur += count[i];
			if (left == -1 && cur >= mid) left = i;
			if (cur >= mid+1) {
				right = i;
				break;
			}
		}
		if (sum % 2==0)
			res[3] = (left + right) / 2.0;
		else
			res[3] = right;

		int m = 0;
		for (int i = 1; i < n; i++) {
			if (count[i] > count[m]) {
				m = i;
			}
		}
		res[4] = m;
		return res;
	}
};