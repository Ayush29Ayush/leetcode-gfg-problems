// refer this for more optimised approach using the concept and properties of CBT and PBT -> https://www.youtube.com/watch?v=CvrPf1-flAA 
//! refer my red classmate copy from last pages to understand the recursion tree.
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
    int countNodes(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int a = countNodes(root->left);
        int b = countNodes(root->right);
        return a+b+1;
    }
};