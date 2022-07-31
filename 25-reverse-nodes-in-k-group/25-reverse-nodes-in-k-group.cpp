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

// https://leetcode.com/problems/reverse-nodes-in-k-group/discuss/1914641/C%2B%2B-Easy-Simple-99-faster-recursive-approach-O(1)-space-complexity

// https://youtu.be/fi2vh0nQLi0?t=902
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        if (head == NULL)
            return head;
        
        ListNode *current = head, *next = NULL, *prev = NULL; 
        ListNode *temp = head;
        
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        
        if (size < k)
            return head;
        // Step1 : reverse first k nodes
        int count = 0;
        while (count != k and current != NULL)
        {
            count++;
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        // Step2 : recursion dekhlega aage ka
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }
        
        // Step3 : return head of reversed linked list
        return prev;
    }
};