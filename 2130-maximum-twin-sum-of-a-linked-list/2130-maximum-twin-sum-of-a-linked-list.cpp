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
/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=L0UnqdfFcV4
    Company Tags                : GOOGLE
    Leetcode Link               : https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
*/


//Approach-1 (Using vector/array)
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> vec;
        
        while(head) {
            vec.push_back(head->val);
            head = head->next;
        }
        
        int i = 0, j = vec.size()-1;
        int result = 0;
        
        while(i < j) {
            result = max(result, vec[i] + vec[j]);
            i++;
            j--;
        }
        
        return result;
    }
};