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

    void preorder(TreeNode* root,vector<int>&v){
        // base condition
        if(root == NULL) 
            return;
        
        // PREORDER -> NLR.
        if(root->left == NULL && root->right == NULL) {
            v.push_back(root->val);
            return;
        }
        preorder(root->left,v);
        preorder(root->right,v);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {

        vector<int>tree1;
        vector<int>tree2;

        preorder(root1,tree1);
        preorder(root2,tree2);

        return tree1 == tree2;
    }
};