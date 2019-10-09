// 并查集
class UnionFindSet {
private:
	const static int count = 26;
	int data[count];
public:
	UnionFindSet() {
		for (int i = 0; i < count; i++) {
			data[i] = i;
		}
	}
	void bing(int i, int j) {
		int a = getSmallest(i);
		int b = getSmallest(j);
		int c = min(a, b);
		data[a] = c;
		data[b] = c;
	}
	int getSmallest(int i) {
		while (data[i]!=i)
		{
			i = data[i];
		}
		return i;
	}
};
class Solution {
public:
	string smallestEquivalentString(string A, string B, string S) {
		if (A.size() == 0) return S;
		UnionFindSet ufs;
		for (int i = 0; i < A.size(); i++) {
			ufs.bing(A[i] - 'a', B[i] - 'a');
		}
		for (int i = 0; i < S.size(); i++) {
			S[i] = ufs.getSmallest(S[i] - 'a') + 'a';
		}
		return S;
	}
};