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

// We can solve this problem with two pointer approach: idea is to make two pointers - fast pointer(jumps two node) and slow pointer(jumps one node). And when fast pointer reaches end, slow pointer would have reached middle element.
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){
            return NULL;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while(fast != NULL && fast->next != NULL ){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = prev->next->next;
        return head;
    }
};