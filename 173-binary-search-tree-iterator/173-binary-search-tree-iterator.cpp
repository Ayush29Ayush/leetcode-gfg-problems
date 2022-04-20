// https://leetcode.com/problems/binary-search-tree-iterator/discuss/1965170/C%2B%2B-Solution-using-Inorder

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
class BSTIterator {
public:
    vector<int> ans;
    int pos;
    void inorder(TreeNode *root)
    {
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    
    
    BSTIterator(TreeNode* root) {
    pos=0;
        inorder(root);
    }
    
    int next() {
        return ans[pos++];
    }
    
    bool hasNext() {
        return ans.size()!=pos;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */