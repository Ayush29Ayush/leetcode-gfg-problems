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

// Using Morris Traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        
        while(root!=NULL)
        {
            if(root->left)
            {
                TreeNode *leftpointer = root->left;
                TreeNode *current = leftpointer;
                while(current->right!=NULL)
                {
                    current=current->right;
                }
                current->right=root->right;//Morris Traversal main step
                root->left=NULL;
                root->right=leftpointer;
            }
            root=root->right;
        }
    }
};