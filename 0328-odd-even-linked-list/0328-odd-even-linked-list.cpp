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

//! MY DISCUSS FORUM SOLUTION => https://leetcode.com/problems/odd-even-linked-list/discuss/2881829/C%2B%2B-oror-EASY-oror-DETAILED-EXPLAINATION-oror-O(N)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) 
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *even_head = even;
        
        while(odd->next && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        
        odd->next = even_head;
        return head;
    }
};