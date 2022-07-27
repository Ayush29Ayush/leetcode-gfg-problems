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
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/2338767/C%2B%2B-3-solutions-Recursion-Stack-Morris-Traversal-Clean-code-Full-Explained
class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode* cur = root;
		TreeNode* pre = NULL;
		while(cur){
			if(cur->left){
				pre = cur->left;
				while(pre->right)pre = pre->right;
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
	}
};