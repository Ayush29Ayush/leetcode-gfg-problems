// https://leetcode.com/problems/copy-list-with-random-pointer/discuss/1841282/commented-readable-c%2B%2B-soln-using-unordered-map

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // create a head for copiedList
        Node* copied  = NULL;
        if( head == NULL ) return copied;
        
        Node* original = head;
        // create a nodeMap to map each node of original list to the corresponding node in copied list
        unordered_map<Node*, Node*> nodeMap;
        // copy the first node of originalList to the copied list and map them
        copied = new Node(original->val);
        nodeMap[original] = copied;
        // traverse the originalList and copy each node of the originalLIst into copiedList and map them
        Node *originalPtr = original->next, *copiedPtr = copied;
        while( originalPtr != NULL )
        {
            copiedPtr->next = new Node(originalPtr->val);
            copiedPtr = copiedPtr->next;
            nodeMap[originalPtr] = copiedPtr;
            originalPtr = originalPtr->next;
        }
        // traverse the originalList again to assign the random pointers of copiedList using nodeMap
        originalPtr = original;
        copiedPtr = copied;
        while( originalPtr != NULL )
        {
            copiedPtr->random = nodeMap[originalPtr->random];
            copiedPtr = copiedPtr->next;
            originalPtr = originalPtr->next;
        }
        
        return copied;
    }
};