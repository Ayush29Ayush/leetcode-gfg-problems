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

// refer this if doubts -> https://youtu.be/pDURIj98e0I?t=261
// class Solution {
// public:
//     bool isBST(TreeNode* root, long min, long max)
//     {
//         if(root==NULL) return true;
        
//         if(root->val > min && root->val < max)
//         {
//             bool left = isBST(root->left, min, root->val);
//             bool right = isBST(root->right, root->val, max);
            
//             return (left && right);
//         }
//         else
//             return false;
//     }
//     bool isValidBST(TreeNode* root) {
//         return isBST(root, LONG_MIN, LONG_MAX);
//     }
// };

//inorder of bst is always sorted and we can check if it is not sorted then it is not BST.
class Solution {
public:
    
    void inorderTraverse(TreeNode* root,vector<int> &inorder){
        //base case
        if(!root){
            return;
        }
        
        //left call.
        inorderTraverse(root -> left,inorder);
        //store while returning from left
        inorder.push_back(root -> val);
        //right call
        inorderTraverse(root -> right,inorder);
    }
    
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inorderTraverse(root,inorder);
        //check if the inorder is sorted.
        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i] >= inorder[i+1]){
                return false;
            }
        }
        return true;
    }
};