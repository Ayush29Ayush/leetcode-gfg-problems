/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        
        while(temp->next!=NULL)
        {
            temp=temp->next;
            n++;
        }
        
        int mid = (n%2==0) ? (n/2) : (n/2+1);
        
        ListNode* node = head;
        int i = 0;
        while(i<mid)
        {
            node=node->next;
            i++;
        }
        
        return node;
    }
};