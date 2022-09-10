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
// babbar approach
class Solution {
public:
    TreeNode* getMin(TreeNode* root){
        //temp is minimum node from that root.
        TreeNode* temp = root ;
        while((temp -> left)){
            temp = temp -> left;
        }
        return temp;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        //! Base Case
        if(root==NULL)
            return root;
        
        if(root->val == key)
        {
            // yahan sab likho
            // if 0 children 
            if(root->right==NULL && root->left == NULL)
            {
                // delete root;
                return NULL;
            }
            // if 1 children either left or right
            if(root->left!=NULL && root->right==NULL)
            {
                TreeNode* temp = root->left;
                // delete root;
                return temp;
            }
            if(root->left==NULL && root->right!=NULL)
            {
                TreeNode* temp = root->right;
                // delete root;
                return temp;
            }
            // if 2 children 
            if(root->left!=NULL && root->right!=NULL)
            {
                TreeNode* rightwalaNode = root->right;
                int mini = getMin(rightwalaNode)->val;
                root -> val = mini;
                root -> right = deleteNode(root -> right,mini);
                return root;
            }
        }
        
        if(root->val < key)
        {
            root->right = deleteNode(root->right, key);
        }
        
        if(root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        
        return root;
    }
};