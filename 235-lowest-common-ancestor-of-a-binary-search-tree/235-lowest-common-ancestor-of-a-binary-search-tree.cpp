/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// https://youtu.be/pDURIj98e0I?t=1695
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root==NULL)
            return NULL;
        
        // if you are in the left part, then find in the right
        if(root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        // if you are in the right part, then find in the left
        else if(root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return root;
    }
};