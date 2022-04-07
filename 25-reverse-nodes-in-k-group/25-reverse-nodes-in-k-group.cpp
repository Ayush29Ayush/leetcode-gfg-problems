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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        if (head == NULL)
            return head;
        ListNode *current = head, *next = NULL, *prev = NULL, *temp = head;
        int size = 0;
        while (temp != NULL)
        {
            size++;
            temp = temp->next;
        }
        if (size < k)
            return head;
        int count = 0;
        while (count != k and current != NULL)
        {
            count++;
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};