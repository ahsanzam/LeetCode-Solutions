// https://leetcode.com/problems/invert-binary-tree/
// Jan 21, 2019
// Famous problem that Max Howell (creator of Homebrew) couldn't solve on a whiteboard at Google

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        TreeNode* left = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(left);
        return root;
    }
};