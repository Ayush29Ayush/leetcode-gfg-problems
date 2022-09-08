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
class bst_node{
    public:
        bool isbst; //if true it means subtree rooted at current bst_node is BST
        int max_val; // It stores minimum value of BST nodes rooted at current bst_node.
        int min_val; // Smilar to max_val.
        int sum; //It stores sum of BST possible in subtree rooted at current bst_node.
};
class Solution {
public:
    bst_node solve(TreeNode* root, int &max_sum){
        if(!root){
            return {true,INT_MIN,INT_MAX,0};
        }
        auto left_info = solve(root->left,max_sum);
        auto right_info = solve(root->right,max_sum);
        bst_node root_info;
        if(left_info.isbst && right_info.isbst && left_info.max_val< root->val && root->val < right_info.min_val){
            root_info.isbst = true;
            root_info.min_val = min(root->val,left_info.min_val);
            root_info.max_val = max(root->val,right_info.max_val);
            root_info.sum = left_info.sum + right_info.sum + root->val;
        }
        else{
            root_info.isbst = false;
            root_info.min_val = min(root->val,left_info.min_val);
            root_info.max_val = max(root->val,right_info.max_val);
            root_info.sum = max(left_info.sum,right_info.sum);
        }
        max_sum  = max(max_sum,root_info.sum);
        return root_info;
    }
    int maxSumBST(TreeNode* root) {
        int max_sum =0;
        solve(root,max_sum);
        return max_sum;
    }
};