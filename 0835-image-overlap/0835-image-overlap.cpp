class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        unordered_map<int, int>map;
        vector<int>v1 , v2;
        for(int i=0; i<n*n; i++)
            if(img1[i/n][i%n]==1)v1.push_back(i/n*100+i%n);
        for(int i=0; i<n*n; i++)
            if(img2[i/n][i%n]==1)v2.push_back(i/n*100+i%n);
        for(auto i:v1)for(auto j:v2)map[i-j]++;
        int ans=0;
        for(auto &[k, v]:map)ans=max(ans, v);
        return ans;
    }
};