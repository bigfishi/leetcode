// 简单 递归，错了好几次，遍历函数没写好
class Solution {
	int dfs(TreeNode* node, int& cur) {
		if (!node) return 0;
		int t = 0, l = -1, r = -1;
		if (node->left) {
			int l2 = dfs(node->left, cur);
			if (node->left->val == node->val) {
				l = l2 + 1;
				t += l;
			}
		}
		if (node->right) {
			int r2 = dfs(node->right, cur);
			if (node->right->val == node->val) {
				r = r2 + 1;
				t += r;
			}
		}
		if (t > cur) {
			cur = t;
		}
		int res = max(0, max(l, r));
		return res;
	}
public:
	int longestUnivaluePath(TreeNode* root) {
		int res = 0;
		dfs(root, res);
		return res;
	}
};