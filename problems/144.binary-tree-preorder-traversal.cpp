// 递归dfs
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res.push_back(root->val);
        vector<int> tmp = preorderTraversal(root->left);
        res.insert(res.end(), tmp.begin(), tmp.end());
        tmp = preorderTraversal(root->right);
        res.insert(res.end(), tmp.begin(), tmp.end());
        return res;
    }
};
// 栈+迭代dfs
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> st;
        st.push(root);
        while (st.size())
        {
            TreeNode* tmp = st.top();
            res.push_back(tmp->val);
            st.pop();
            if (tmp->right)
                st.push(tmp->right);
            if (tmp->left)
                st.push(tmp->left);
        }
        return res;
    }
};
// 莫里斯遍历(Morris Traversal) https://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
// 实现O(N) S(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* cur = root, *prev;
        while (cur)
        {
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else {
                prev = cur->left;
                while (prev->right&&prev->right != cur)
                {
                    prev = prev->right;
                }

                if (!prev->right) {
                    res.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                }
                else {
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
};