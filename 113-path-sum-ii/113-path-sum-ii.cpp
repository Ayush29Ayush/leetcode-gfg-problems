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
     void solve(TreeNode *root,int targetSum,vector<int> ds,vector<vector<int>> &ans)
    {
        // base case
        if(root==NULL) return;
        // if not base case then add to ds and targetSum = difference to target and root value
        ds.push_back(root->val);
        targetSum=targetSum-root->val;
        
        // when targetSum is finally 0 means we have got our reqd elements in an 1D vec, so push them to 2D vec 
        if(targetSum==0 && root->left==NULL && root->right==NULL)
        {
            ans.push_back(ds);
            return;
        }
        
        // if non of the above condition is satisfied then again call for left and right 
        solve(root->left,targetSum,ds,ans);
        solve(root->right,targetSum,ds,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(root,targetSum,ds,ans);
        return ans;
    }
};