// 简单
// 错误，没考虑光递增不递减的情况
class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		int n = A.size();
		if (n < 3) return false;
		int t = A[0];
		bool inc = true;
		bool changed = false;
		for (int i = 1; i < n; i++) {
			if (A[i] > t) {
				if (!inc) return false;
				t = A[i];
			}
			else if (A[i] < t) {
				if (inc) inc = false;
				t = A[i];
			}
			else {
				return false;
			}
		}
		return true;
	}
};
// 错误，没考虑光递减不递增的情况
class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		int n = A.size();
		if (n < 3) return false;
		int t = A[0];
		bool inc = true;
		bool changed = false;
		for (int i = 1; i < n; i++) {
			if (A[i] > t) {
				if (!inc) return false;
				t = A[i];
			}
			else if (A[i] < t) {
				if (inc) inc = false;
				t = A[i];
			}
			else {
				return false;
			}
		}
		return !inc;
	}
};
// 正确
// 设置2个变量记录递增和递减的数量，设置1个标志位标识当前递增
// 遇到递减重置标志位为false，相等则返回false，遇到该递增不递增或者该递减不递减的情况下也返回false，循环结束判断递增和递减计数都大于0则返回true，否则返回false
class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		int n = A.size();
		if (n < 3) return false;
		int t = A[0];
		bool inc = true;
		int ic = 0, id = 0;
		for (int i = 1; i < n; i++) {
			if (A[i] > t) {
				if (!inc) return false;
				ic++;
				t = A[i];
			}
			else if (A[i] < t) {
				if (inc) inc = false;
				id++;
				t = A[i];
			}
			else {
				return false;
			}
		}
		if (ic&&id) return true;
		else return false;
	}
};