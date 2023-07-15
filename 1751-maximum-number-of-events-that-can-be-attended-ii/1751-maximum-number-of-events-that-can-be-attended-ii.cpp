/*
      NOTE - Since this is actually a DP problem (we memoize it), that's why the video is tagged as DP)
      MY YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=9ykgLt25X9c
      Company Tags                : AMAZON
      Leetcode Link               : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
      Similar Leetcode Qn         : Maximum Profit in Job Scheduling (YouTube  : https://www.youtube.com/watch?v=LL0tVxlAeV4
*/

//Approach - (Without doing any linear or binary search) - Simply keep track of last taken event
class Solution {
public:
    int n;
    vector<vector<int>> t;
    int solve(vector<vector<int>>& events, int i, int prev, int k) {
        
        if(k == 0 || i == n)
            return 0;
        
        if(t[prev+1][k] != -1) //prev+1 because intially prev is = -1
            return t[prev+1][k];
        
        int start = events[i][0];
        int endt   = events[i][1];
        int value = events[i][2];
        
        
        int take = 0, skip = 0;
        if(prev == -1 || events[prev][1] < events[i][0]) {
            take = value + solve(events, i+1, i, k-1);
        }   
        
        skip = solve(events, i+1, prev, k);
        
        return t[prev+1][k] = max(take, skip);
        
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        
        auto lambda = [&](auto &a, auto &b) {
            if(a[1]==b[1])  
                return a[0]-b[0];
            
            return a[1]-b[1];
        };
        
        sort(begin(events), end(events));
        
        n = events.size();
        
        t.resize(n+1, vector<int>(k+1, -1));
        
        return solve(events, 0, -1, k);
    }
};