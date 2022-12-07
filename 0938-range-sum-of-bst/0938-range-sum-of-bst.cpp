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

//Inorder traversal of BST returns nodes in sorted order.
// While sorting nodes by using inorder traversal, we sum up all the nodes values lies between the range.
class Solution {
public:
    void inorder(TreeNode* root, int &low, int &high, int &sum)
    {
        if(root==NULL)
            return;
        
        //INORDER -> LNR
        inorder(root->left, low, high, sum);
        if(low <= root->val && root->val <= high)
            sum += root->val;
        inorder(root->right, low, high, sum);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        inorder(root, low, high, sum);
        return sum;
    }
};