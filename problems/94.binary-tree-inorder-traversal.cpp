// 最简单的方法，dfs方法,递归实现
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return {};
		vector<int> left = inorderTraversal(root->left);
		left.push_back(root->val);
		vector<int> right = inorderTraversal(root->right);
		left.insert(left.end(), right.begin(), right.end());
		return left;
	}
};
// 同样是dfs方法，栈+迭代实现
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int> res;
		unordered_map<TreeNode*, bool> hash;
		// 1. 找最左节点，把过程中的所有节点都压栈
		// 2. 记录并标记栈顶节点，找右节点，无右节点则弹出，有右节点则在右节点执行步骤1
		// 3. 如果栈顶节点被标记，则弹出，执行步骤2
		// 4. 栈空结束
		TreeNode* cur = root;
		while (true)
		{
			while (cur)
			{
				st.push(cur);
				cur = cur->left;
			}
			while (true)
			{
				if (!st.size()) return res;
				TreeNode* tmp = st.top();
				hash[tmp] = true;
				res.push_back(tmp->val);
				if (tmp->right) {
					cur = tmp->right;
					break;
				}
				else {
					st.pop();
				}
				while (true)
				{
					if (!st.size()) return res;
					TreeNode* tmp = st.top();
					if (hash[tmp]) {
						st.pop();
					}
					else {
						break;
					}
				}
			}
		}
		return res;
	}
};
// 改进的递归dfs方法
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		dfs(root, res);
		return res;
	}
private:
	void dfs(TreeNode* node, vector<int>& list) {
		if (!node) return;
		dfs(node->left, list);
		list.push_back(node->val);
		dfs(node->right, list);
	}
};
// 改进的栈+迭代dfs方法
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		set<TreeNode*> visited;
		stack<TreeNode*> st;
		st.push(root);
		while (st.size())
		{
			TreeNode* cur = st.top();
			while (cur && cur->left && visited.find(cur->left)==visited.end())
			{
				st.push(cur->left);
				cur = cur->left;
			}
			res.push_back(cur->val);
			st.pop();
			visited.insert(cur);
			if (cur->right) {
				st.push(cur->right);
			}
		}
		return res;
	}
};
// 莫里斯遍历(Morris Traversal) https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
// 实现O(N) S(1)
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		TreeNode* cur = root, *preNode;
		while (cur)
		{
			if (cur->left) {
				preNode = cur->left;
				while (preNode->right && preNode->right!=cur)
				{
					preNode = preNode->right;
				}

				if (!preNode->right) {
					preNode->right = cur;
					cur = cur->left;
				}
				else {
					preNode->right = NULL;
					res.push_back(cur->val);
					cur = cur->right;
				}
			}
			else {
				res.push_back(cur->val);
				cur = cur->right;
			}
		}
		return res;
	}
};