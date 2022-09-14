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
// https://leetcode.com/problems/path-sum/discuss/1285179/Simplest-C%2B%2B-solution.-EASY-to-understand.v
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum)
    {
        if(root == NULL)
        {
            return false;
        }
        if(root->left == NULL && root->right == NULL && root->val - targetSum == 0)
        {
            return true;
        }
        
        bool left = hasPathSum(root->left,targetSum - root->val);
        bool right = hasPathSum(root->right,targetSum - root->val);
        
        return left || right;
    }
};