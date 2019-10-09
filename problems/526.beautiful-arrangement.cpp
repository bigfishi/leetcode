// 用类似全排列的方法，错误，N=10时，我的结果是615，答案是700
class Solution {
	int N;
	int res;
	bool isBeautiful(int n, int m) {
		if (n % m == 0 || m / n == 0)
			return true;
		return false;
	}
	void backTrack(vector<int> list, int index) {
		if (index == N + 1) {
			res++;
			return;
		}
		for (int i = index; i < N + 1; i++) {
			swap(list[index], list[i]);
			if (isBeautiful(list[index], index) && isBeautiful(list[i], i)) {
				backTrack(list, index + 1);
			}
			swap(list[index], list[i]);
		}
	}
public:
	int countArrangement(int N) {
		this->N = N;
		this->res = 0;
		vector<int> list;
		for (int i = 0; i < N + 1; i++) {
			list.push_back(i);
		}
		backTrack(list, 1);
		return res;
	}
};
// 参考
class Solution {
	int count = 0;
	void backTrack(vector<int>& list, int index, int N, vector<bool>& visited) {
		if (index == N + 1) {
			count++;
			return;
		}
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) {
				visited[i] = true;
				if (index % i == 0 || i % index == 0) {
					backTrack(list, index + 1, N, visited);
				}
				visited[i] = false;
			}
		}
	}
public:
	int countArrangement(int N) {
		vector<int> list;
		vector<bool> visited;
		for (int i = 0; i <= N; i++) {
			list.push_back(i);
			visited.push_back(false);
		}
		backTrack(list, 1, N, visited);
		return count;
	}
};
// 用类似全排列的方法，需要注意的是，判断是否进行index+1只需要判断index是否优雅即可，不需要判断循环变量i
class Solution {
	int N;
	int res;
	bool isBeautiful(int n, int m) {
		if (n % m == 0 || m / n == 0)
			return true;
		return false;
	}
	void backTrack(vector<int> list, int index) {
		if (index == N + 1) {
			res++;
			return;
		}
		for (int i = index; i < N + 1; i++) {
			swap(list[index], list[i]);
			if (isBeautiful(list[index], index)) {
				backTrack(list, index + 1);
			}
			swap(list[index], list[i]);
		}
	}
public:
	int countArrangement(int N) {
		this->N = N;
		this->res = 0;
		vector<int> list;
		for (int i = 0; i < N + 1; i++) {
			list.push_back(i);
		}
		backTrack(list, 1);
		return res;
	}
};