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
// https://www.youtube.com/watch?v=IGHyX15fLI8&list=PLDzeHZWIZsTryvtXdMr6rPh4IDexB5NIA&index=77
class Solution {
public:
    void solve(TreeNode* root, vector<int> &inorder)
    {
        // base case
        if(root==NULL)
            return;
        
        // LNR
        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        solve(root, inorderVal);
        
        int i = 0;
        int j = inorderVal.size()-1;
        
        while(i<j)
        {
            if(inorderVal[i]+inorderVal[j] == k)
                return true;
            else if(inorderVal[i]+inorderVal[j] > k)
                j--;
            else if(inorderVal[i]+inorderVal[j] < k)
                i++;
        }
        return false;
    }
};