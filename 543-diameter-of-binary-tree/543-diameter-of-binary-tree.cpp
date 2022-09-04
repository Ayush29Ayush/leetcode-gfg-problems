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
    //concept is same as calculating height of left and right subtree while making one diameter variable and check max of diameter and left+right.
    int depth(TreeNode* root,int &diameter){
        //base case
        if(!root){
            return 0;
        }
        
        int ld = depth(root -> left,diameter);
        int rd = depth(root -> right,diameter);
        
        diameter = max(diameter,ld + rd);
        return max(ld,rd) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        depth(root,diameter);
        return diameter;
    }
};