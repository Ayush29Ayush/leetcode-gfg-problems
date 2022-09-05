/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
//https://leetcode.com/problems/n-ary-tree-level-order-traversal/discuss/2532374/Easy-solution-Explained-oror-Beginner-Friendly-oror-Best-Method

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int> temp;
            int s = q.size();
            
            for(int i = 0; i < s; i++){
                temp.push_back(q.front()->val);
                
                Node* temp = q.front();
                q.pop();
                
                for(Node* child : temp->children)
                q.push(child);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};