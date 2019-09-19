// 参考105.construct-binary-tree-from-preorder-and-inorder-traversal
class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		unordered_map<int, int> inorderMap;
		for (size_t i = 0; i < inorder.size(); i++)
		{
			inorderMap[inorder[i]] = i;
		}
		int n = inorder.size();
		int index = n-1;
		int left = 0, right = n;
		TreeNode* root = dfs(postorder, inorderMap, index, left, right);
		return root;
	}
private:
	TreeNode* dfs(vector<int>& postorder, unordered_map<int, int>& inorderMap, int& index, int left, int right) {
		if (left >= right) return NULL;
		int val = postorder[index];
		int t = inorderMap[val];
		TreeNode* node = new TreeNode(val);
		index--;
		node->right = dfs(postorder, inorderMap, index, t + 1, right);
		node->left = dfs(postorder, inorderMap, index, left, t);
		return node;
	}
};