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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        vector<int> vec;
        
        while(temp!=NULL)
        {
            vec.push_back(temp->val);
            temp = temp->next;
        }
        
        reverse(vec.begin(), vec.end());
        
        int ans=0;
        for(int i=0; i<vec.size(); i++)
        {
            ans += vec[i]*pow(2,i);
        }
        
        return ans;
    }
};