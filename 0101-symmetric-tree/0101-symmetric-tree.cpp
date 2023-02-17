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
    bool isSymmetric(TreeNode* root) {
        // Special case...
        if(root == nullptr) return true;
        // Return the function recursively...
        return isSymmetric(root->left,root->right);
    }
    // A tree is called symmetric if the left subtree must be a mirror reflection of the right subtree...
    bool isSymmetric(TreeNode* leftroot,TreeNode* rightroot){
        // If both root nodes are null pointers, return true...
        if(!leftroot && !rightroot)  return true;
        // If exactly one of them is a null node, return false...
        if(!leftroot || !rightroot)  return false;
        // If root nodes haven't same value, return false...
        if(leftroot->val != rightroot->val)  return false;
        // Return true if the values of root nodes are same and left as well as right subtrees are symmetric...
        return isSymmetric(leftroot->left, rightroot->right) && isSymmetric(leftroot->right, rightroot->left);
    }
};