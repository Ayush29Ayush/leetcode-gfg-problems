class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int size = tops.size();
        vector<int> freq1(7,0); // freq1 for tops
        vector<int> freq2(7,0); // freq2 for bottoms
        vector<int> freq3(7,0); // freq3 for equal elements in tops and bottom
        
        // teeno freq vectors mein individual elements ki freq store kar diya
        for(int i=0; i<size; i++)
        {
            freq1[tops[i]]++;
            freq2[bottoms[i]]++;
            
            if(tops[i]==bottoms[i])
                freq3[tops[i]]++;
        }
        
        int ans = INT_MAX;
        
        for(int i = 1; i<=6; i++)
        {
            if(freq1[i] + freq2[i] - freq3[i] == size)
            {
                int minimumswap = min(freq1[i],freq2[i]) - freq3[i];
                ans = min(ans,minimumswap);
                return ans;
            }
        }
        
        return -1;
        
    }
};