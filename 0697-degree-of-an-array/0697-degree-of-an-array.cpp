class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        
        unordered_map<int, int> freq, firstIndex;

        int minLen= INT_MAX, degree= 0;
        for(int i=0; i<nums.size(); i++)
        {
            freq[nums[i]]++;

            //checking if we are getting the current element first time or not and if yes
            //then we are saving its index value into firstIndex map

            if(freq[nums[i]] == 1)
                firstIndex[nums[i]] = i;

            // if current frequency is equals to the degree of an array then we have to
            //check current subarrays length and according to that we have to update 
            //the minimum length 

            if(freq[nums[i]] == degree)
            {
                int currLen= i - firstIndex[nums[i]] + 1;
                if(minLen > currLen)
                    minLen= currLen;
            }

            //we are updating degree dynamically(in the runtime) so for each iteration
            //we have to check the degree and if current frequency is greater then the
            //degree then we would update the degree as well as the minimum length 
            //because this is the first time where we are getting the highest degree and 
            //no other elements before this, contains the maximum degree

            if(freq[nums[i]] > degree)
            {
                minLen = i - firstIndex[nums[i]] + 1;
                degree = freq[nums[i]];
            }
        }

        return minLen;
    }
};