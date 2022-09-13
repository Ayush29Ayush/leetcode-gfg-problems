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
    class compare{ //comaprator for max-heap priority queue
      public:
        bool operator()(ListNode* first, ListNode* second){
            return first->val > second->val;
        }
    };
    
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            // could be solved using a min - priority queue of 
            // insert first node of each list, create the final list
            // one at a time from the nodes popped from the heap

            priority_queue<ListNode*, vector<ListNode*>, compare>heap;
            for(int i=0; i<lists.size();i++){
             if(lists[i])
                heap.push(lists[i]);
            }
            ListNode *dummy= new ListNode(0);
            ListNode *head = dummy;
            while(!heap.empty()){
                head->next = heap.top();
                heap.pop();
                if(head->next && head->next->next) //do not push null in the heap, compare will fail
                    heap.push(head->next->next);
                head = head->next;

            } 
            return dummy->next;
        }
};