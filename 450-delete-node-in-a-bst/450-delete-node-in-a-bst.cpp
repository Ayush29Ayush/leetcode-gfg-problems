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
//babbar approach.
//algo is just check whether given node is in left part or in right part or it is the root itself. if found ,then it has four states 0,1,2 children but the catch is in 2 children -left,right. So in that case just check lowest node in root->right and simply copy that in root node and store it in mini variable and root -> right is given in delete call to delete mini and return root.

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
        //babbar approach.
        //base case
        if(root == NULL){
            return NULL;
        }
        if(root -> val == key){
            //if no child.
            if(!(root -> left) && !(root -> right)){
                return NULL;
            }
            //means left child is not null
            else if((root -> left) && !(root -> right)){
                return root -> left;
            }
            else if(!(root -> left) && (root -> right)){
                return root -> right;
            }
            else{
                //do child hai aur isi ko handle karna hai.
                //root -> right me jaao aur smallest element ko root me copy kardo.
                TreeNode* rightNode = root -> right;
                int mini = getMin(rightNode) -> val;
                root -> val = mini;
                //now call delete function and delete the mini node .
                root -> right = deleteNode(root -> right,mini);
                return root;
            }
        }
        else if(root -> val > key){
            //left me jao
            root -> left = deleteNode(root -> left,key);
        }
        else{
            //right me jao
            root -> right = deleteNode(root -> right,key);
        }
       return root;
    }
};