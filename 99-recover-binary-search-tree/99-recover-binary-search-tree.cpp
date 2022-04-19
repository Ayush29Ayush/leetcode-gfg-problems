// https://leetcode.com/problems/recover-binary-search-tree/discuss/1962281/C%2B%2B-oror-Easy-to-understand

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
	TreeNode* firstMistake, *secondMistake, *pre;
	void recoverTree(TreeNode* root) {
		pre = new TreeNode(INT_MIN);
		inorder(root);
		swap(firstMistake->val, secondMistake->val);
	}

	void inorder(TreeNode* root) {
		if(root == nullptr) 
			return;

		inorder(root->left);

		if(firstMistake == nullptr && root->val < pre->val)
			firstMistake = pre;
		if(firstMistake != nullptr && root->val < pre->val)
			secondMistake = root;
		pre = root;

		inorder(root->right);
	}
};