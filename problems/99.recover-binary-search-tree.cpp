// 二叉搜索树，中序遍历是递增的，先中序遍历获取列表，从前找到一个比后面元素大的节点，从后向前找到一个比前面元素小的节点，交换之后，再中序遍历，把值插入
class Solution {
public:
	void recoverTree(TreeNode* root) {
		vector<int> list;
		dfs(root, list);
		int x, y;
		for (size_t i = 1; i < list.size(); i++)
		{
			if (list[i] < list[i - 1]) {
				x = i - 1;
				break;
			}
		}
		for (size_t i = list.size()-2; i >= 0; i--)
		{
			if (list[i] > list[i + 1]) {
				y = i + 1;
				break;
			}
		}
		int tmp = list[x];
		list[x] = list[y];
		list[y] = tmp;
		int index = 0;
		dfs2(root, list, index);
	}
private:
	void dfs(TreeNode* node, vector<int>& list) {
		if (node) {
			if (node->left) {
				dfs(node->left, list);
			}
			list.push_back(node->val);
			if (node->right) {
				dfs(node->right, list);
			}
		}
	}
	void dfs2(TreeNode* node, vector<int>& list, int& index) {
		if (node) {
			if (node->left) {
				dfs2(node->left, list, index);
			}
			node->val = list[index++];
			if (node->right) {
				dfs2(node->right, list, index);
			}
		}
	}
};
// 莫里斯遍历实现，S(1) 空间复杂度为常量
class Solution {
public:
	void recoverTree(TreeNode* root) {
		TreeNode* cur = root, *preNode = NULL, *node1 = NULL, *node2 = NULL, *lastNode = NULL;
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
					// 原中序输出位置
					if (lastNode && lastNode->val > cur->val) {
						if (node1) {
							node2 = cur;
						}
						else {
							node1 = lastNode;
							node2 = cur;
						}
					}
					lastNode = cur;
					preNode->right = NULL;
					cur = cur->right;
				}
			}
			else {
				// 原中序输出位置
				if (lastNode && lastNode->val > cur->val) {
					if (node1) {
						node2 = cur;
					}
					else {
						node1 = lastNode;
						node2 = cur;
					}
				}
				lastNode = cur;
				cur = cur->right;
			}
		}
		if (node1 && node2) {
			int tmp = node1->val;
			node1->val = node2->val;
			node2->val = tmp;
		}
	}
};