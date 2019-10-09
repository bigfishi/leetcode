// 中等 根据左边界，叶子结点，右边界做，难度不大。错了一次，误解了题意，题目说不能有重复节点，可以有重复值，我理解成不能有重复数了。
class Solution {
	void leftBoundry(TreeNode* root, vector<TreeNode*>& list) {
		if (root) list.push_back(root);
		else return;
		if (!root->left) return;
		TreeNode* cur = root->left;
		while (cur)
		{
			list.push_back(cur);
			if (cur->left) cur = cur->left;
			else if (cur->right) cur = cur->right;
			else cur = NULL;
		}
	}
	void rightBoundry(TreeNode* root, vector<TreeNode*>& list) {
		if (root) list.push_back(root);
		else return;
		if (!root->right) return;
		TreeNode* cur = root->right;
		while (cur)
		{
			list.push_back(cur);
			if (cur->right) cur = cur->right;
			else if (cur->left) cur = cur->left;
			else cur = NULL;
		}
	}
	void leafNode(TreeNode* root, vector<TreeNode*>& list) {
		if (!root) return;
		if (!root->left && !root->right) {
			list.push_back(root);
			return;
		}
		leafNode(root->left, list);
		leafNode(root->right, list);
	}
public:
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		vector<TreeNode*> lb, ln, rb;
		leftBoundry(root, lb);
		leafNode(root, ln);
		rightBoundry(root, rb);
		reverse(rb.begin(), rb.end());
		map<TreeNode*, int> record;
		for (int i = 0; i < lb.size(); i++) {
			if (record.find(lb[i]) == record.end()) {
				record[lb[i]]++;
				res.push_back(lb[i]->val);
			}
		}
		for (int i = 0; i < ln.size(); i++) {
			if (record.find(ln[i]) == record.end()) {
				record[ln[i]]++;
				res.push_back(ln[i]->val);
			}
		}
		for (int i = 0; i < rb.size(); i++) {
			if (record.find(rb[i]) == record.end()) {
				record[rb[i]]++;
				res.push_back(rb[i]->val);
			}
		}
		return res;
	}
};