/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (inorder.empty()) {
            return nullptr;
        }

        int rootValue = preorder[0];
        preorder.erase(preorder.begin());

        int ind = find(inorder.begin(), inorder.end(), rootValue) - inorder.begin();

        TreeNode* root = new TreeNode(rootValue);

        vector<int> leftInorder(inorder.begin(), inorder.begin() + ind);
        vector<int> rightInorder(inorder.begin() + ind + 1, inorder.end());

        root->left = buildTree(preorder, leftInorder);
        root->right = buildTree(preorder, rightInorder);

        return root;
    }
};