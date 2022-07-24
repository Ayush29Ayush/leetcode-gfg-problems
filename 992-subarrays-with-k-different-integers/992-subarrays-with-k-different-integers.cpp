//the main concept is rather than finding for exact k diff elements we will be finding atmost k diff elements subarray and k-1 atmost subarrays and subtract both to get exact k diff elements subarrays. We will check for the new element nums[i] whether is is not seen before then update count .Then check count should be less than equal to k and append it in totsum = i-j+1. Else increment j pointer and decrement freq of nums[j] and count-- if freq of nums[j]==0 and update totsum with (i-j+1). 
class Solution {
public:
    int solve(vector<int> nums,int k){
        unordered_map<int,int> mp;
        int count=0;
        int j=0;
        int totsum=0;
        int n=nums.size();
        //for storing frequency of map elements.
        vector<int> freq(n+1,0);
        for(int i=0;i<n;i++){
            if(freq[nums[i]]==0){
                count++;
            }
            freq[nums[i]]++;
            //checking for the distinct elements.
            if(count<=k)
                totsum+=i-j+1;//window size is i-j+1...
            else{
                while(count>k){
                    freq[nums[j]]--;
                    if(freq[nums[j]]==0)
                        count--;
                    
                    j++;
                }
                totsum+=(i-j+1);
            }
        }
        
        return totsum;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return solve(nums,k)-solve(nums,k-1);
    }
};