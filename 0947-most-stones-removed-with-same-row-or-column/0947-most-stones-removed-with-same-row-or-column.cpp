class Solution {
public:
    vector<int> parent;
    int find(int x) {
        return parent[x] == x ? x : find(parent[x]);
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n = (int) stones.size();
        parent.resize(n + 1, 0);
        // at the beginning, each element is in its own group
        for(int i = 0; i <= n; i++) parent[i] = i;
        // iterate each pair
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // if two stones shares the same row or the same column
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    // get the root of `i`
                    int a = find(i);
                    // get the root of `j`
                    int b = find(j);
                    // if they don't belong to the same group, unite them together
                    if(a != b) parent[b] = a;
                }
            }
        }
        int connected = 0;
        // if `i` is the root, then we found a new connected component
        for(int i = 0; i < n; i++) connected += parent[i] == i;
        // the max number of stones that can be removed is simply
        // the total count - the number of the connected components
        return n - connected;
    }
};