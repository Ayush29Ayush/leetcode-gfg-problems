/*
    MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=4fiZOJpis9g
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/time-needed-to-inform-all-employees/
*/


//Approach-1 (Using DFS) - O(N) because we visit each node only once.
class Solution {
public:
    
    int maxTime = INT_MIN;
    
    void DFS(unordered_map<int, vector<int>> &adj, vector<int>& informTime, int curr_employee, int curr_time) {
        maxTime = max(maxTime, curr_time);
        
        for(int &v : adj[curr_employee]) {
            
            DFS(adj, informTime, v, curr_time + informTime[curr_employee]);
            
        }
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> adj;
        
        for(int i = 0; i < manager.size(); i++) {
            int child     = i;
            int manager_i = manager[i];
            
            if(manager_i != -1)
                adj[manager_i].push_back(child);
        }
        
        DFS(adj, informTime, headID, 0);
        return maxTime;
    }
};
