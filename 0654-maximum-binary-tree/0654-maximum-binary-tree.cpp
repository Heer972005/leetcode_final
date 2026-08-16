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

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    int maxIndex(vector<int>& nums, int left, int right) {
        int index = left;

        for (int i = left; i <= right; i++) {
            if (nums[i] > nums[index]) {
                index = i;
            }
        }

        return index;
    }

    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int currMaxIndex = maxIndex(nums, left, right);

        TreeNode* root = new TreeNode(nums[currMaxIndex]);

        root->left = build(nums, left, currMaxIndex - 1);
        root->right = build(nums, currMaxIndex + 1, right);

        return root;
    }
};