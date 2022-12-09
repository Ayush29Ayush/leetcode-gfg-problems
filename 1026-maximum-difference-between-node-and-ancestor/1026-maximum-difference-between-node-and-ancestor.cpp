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
    void find(TreeNode* root,int mx,int mn,int& ans)
    {
        if(root==NULL) return;

        // finding max and min for a particular part (left and right part)
        if(mx < root->val) mx = root->val;
        
        if(mn > root->val) mn = root->val;

        // store the mx and min diff and each time store max
        ans = max(ans,abs(mx-mn));

        find(root->left,mx,mn,ans);         // left call
        find(root->right,mx,mn,ans);        // right call
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        int ans = INT_MIN;
        find(root,root->val,root->val,ans);
        return ans;
    }
};