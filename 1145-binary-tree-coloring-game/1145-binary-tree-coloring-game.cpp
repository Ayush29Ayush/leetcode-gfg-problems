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
    int count(TreeNode* root)
    {
        if(root==NULL) return 0;

        return 1+count(root->left)+count(root->right);
    }

    TreeNode* find(TreeNode*root,int x)
    {
        if(root==NULL)
            return NULL;
        if(root->val==x)
            return root;

        TreeNode* l=find(root->left,x);
        TreeNode* r=find(root->right,x);
        if(l==NULL) return r;
        return l;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
       TreeNode* xpos=find(root,x);
       int a=count(xpos->left);
       int b=count(xpos->right);
       int c=n-a-b-1;
       if(a>b+c) return true;
       if(b>a+c) return true;
       if(c>a+b) return true;
       return false;
    }
};