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
// https://youtu.be/IGHyX15fLI8?t=2791
class Solution {
private:
    TreeNode* solve(vector<int> &preorder, int mini, int maxi, int &i) {
    // if array ke size se bahar nikal gaya then return NULL
    if(i>=preorder.size())
        return NULL;
    
    //     if range se bahar nikal gaya
    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;
    
    // if range mein hai then node banado
    TreeNode* root = new TreeNode(preorder[i++]);
    
    // then left aur right ke liye call lagado
    root->left = solve(preorder, mini, root->val, i);
    root->right = solve(preorder, root->val, maxi, i);
    
    return root;
    
}
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN;
        int maxi = INT_MAX;
        int index = 0;
        return solve(preorder, mini, maxi, index);
    }
};