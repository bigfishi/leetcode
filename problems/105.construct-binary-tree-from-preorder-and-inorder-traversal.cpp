// 递归dfs方法，自己没有思路，这是参考别人的代码
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		unordered_map<int, int> inorderMap;
		for (size_t i = 0; i < inorder.size(); i++)
		{
			inorderMap[inorder[i]] = i;
		}
		int n = preorder.size();
		int index = 0;
		int left = 0, right = n;
		TreeNode* root = dfs(preorder, inorderMap, index, left, right);
		return root;
	}
private:
	TreeNode* dfs(vector<int>& preorder, unordered_map<int, int>& inorderMap, int& index, int left, int right) {
		if (left >= right) return NULL;
		int val = preorder[index];
		int t = inorderMap[val];
		TreeNode* node = new TreeNode(val);
		index++;
		node->left = dfs(preorder, inorderMap, index, left, t);
		node->right = dfs(preorder, inorderMap, index, t + 1, right);
		return node;
	}
};