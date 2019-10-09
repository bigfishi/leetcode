// 困难 stack实现，需要记录高度
class Solution {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		if (n < 3) return 0;
		stack<int> st;
		int h = 0;
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (!st.size()) {
				st.push(i);
				h = 0;
			}
			else {
				int t = st.top();
				if (height[t] >= height[i]) {
					st.push(i);
				}
				else {
					while (st.size() && height[st.top()]<=height[i])
					{
						t = st.top();
						st.pop();
						res += (i - t - 1)*(min(height[t], height[i]) - h);
						h = min(height[t], height[i]);
					}
					if (st.size()) {
						t = st.top();
						res += (i - t - 1)*(min(height[t], height[i]) - h);
						h = min(height[t], height[i]);
					}
					else {
						h = 0;
					}
					st.push(i);
				}
			}
		}
		return res;
	}
};