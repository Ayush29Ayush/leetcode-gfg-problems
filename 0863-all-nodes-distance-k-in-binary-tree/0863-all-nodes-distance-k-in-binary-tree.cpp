/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>visited(500,0);
        vector<int>ans;
        if(!root)return ans;
        map<TreeNode*,TreeNode*>m;
        parents(root,m);

        queue<pair<TreeNode*,int>>q;
        visited[target->val]=1;
        q.push({target,0});

        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            cout<<level<<" "<<node->val<<endl;
            if(level==k)ans.push_back(node->val);
            if(level>k)break;

            if(node->left and !visited[node->left->val]){
            visited[node->left->val]=1;
            q.push({node->left,level+1});
            }
            if(node->right and !visited[node->right->val]){
            visited[node->right->val]=1;
            q.push({node->right,level+1});
            }
            if(m[node] and !visited[(m[node])->val]){
                visited[(m[node])->val]=1;
                q.push({m[node],level+1});
            }

        }
        return ans;
    }

    void parents(TreeNode *root,map<TreeNode*,TreeNode*>&m){
        if(!root)return;

        if(root->left){
            m[root->left]=root;
            parents(root->left,m);
        }
        if(root->right){
            m[root->right]=root;
            parents(root->right,m);
        }
    }
};