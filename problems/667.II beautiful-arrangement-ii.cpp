// 刚开始想参考全排列的实现，发现做不出来
// 改为直接参考
// 这题可以理解为数学题，脑洞题。通过例子得出规律，[1]是1，[2]是[1]+k，[3]是[2]-(k-1)，[4]是[3]+(k-2)，以此类推，k为0时，[k]是k
class Solution {
public:
	vector<int> constructArray(int n, int k) {
		vector<int> list;
		list.push_back(1);
		bool flag = true;
		int size = 1;
		while (size<n)
		{
			if (k == 0) {
				list.push_back(size + 1);
			}
			else {
				if (flag)
					list.push_back(list[size - 1] + k);
				else
					list.push_back(list[size - 1] - k);
				k--;
				flag = !flag;
			}
			size++;
		}
		return list;
	}
};