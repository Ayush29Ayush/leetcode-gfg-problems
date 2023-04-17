class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<bool> result(n,false);
        
        int maxC = *max_element(candies.begin(),candies.end());
        
        for(int i=0; i<n; i++)
        {
            if(candies[i] + extraCandies >= maxC)
            {
                result[i] = true;
            }
        }
        
        return result;
    }
};