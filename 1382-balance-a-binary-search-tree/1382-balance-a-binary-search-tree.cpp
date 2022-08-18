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

// https://youtu.be/IGHyX15fLI8?t=1950

class Solution {
public:
    void solve(TreeNode* root, vector<int> &inorder)
    {
        // base case
        if(root==NULL)
            return;
        solve(root->left, inorder);
        inorder.push_back(root->val);
        solve(root->right, inorder);
    }
    
    TreeNode* inorderToBST(int s, int e, vector<int> inorderVal)
    {
        // base case
        if(s>e)
        {
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode (inorderVal[mid]);
        root->left = inorderToBST(s, mid-1, inorderVal);
        root->right = inorderToBST(mid+1, e, inorderVal);

        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorderVal;
    // store values in sorted order using inorder traversal
    solve(root, inorderVal);
    
    root =  inorderToBST(0, inorderVal.size()-1, inorderVal);
    return root;
    }
};