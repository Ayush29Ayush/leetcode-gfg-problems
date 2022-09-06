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
// https://leetcode.com/problems/binary-tree-pruning/discuss/2537336/C%2B%2B-or-Recursion-Approach

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root!=NULL){
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            if(!root->left && !root->right && root->val==0)
                return NULL;
        }
        return root;
    }
};