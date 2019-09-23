// 花费5分钟，写代码2分钟，然后错误，发现输出没有按题意来，然后改有错，发现修改出了个小问题，最后总共5分钟
class Solution {
	void findPath(TreeNode* node, vector<string>& res, string& str) {
		if (!node) return;
		string t;
		if (str.size() == 0)
			t = to_string(node->val);
		else
			t = str + "->" + to_string(node->val);
		if (node->left)
			findPath(node->left, res, t);
		if (node->right)
			findPath(node->right, res, t);
		if (!node->left && !node->right)
			res.push_back(t);
	}
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		string t = "";
		findPath(root, res, t);
		return res;
	}
};