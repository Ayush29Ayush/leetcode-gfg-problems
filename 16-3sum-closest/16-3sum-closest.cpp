class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int diff=INT_MAX;
        int ans=0;
        
        //optimized approach ,check if there are 3 
        for(int i=0;i<n-2;i++){
            // if(i>0 && nums[i]==nums[i-1])
            //     continue;
            
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=0;
                sum=nums[i]+nums[start]+nums[end];
                if(sum>target){
                    end--;
                }
                else if(sum<target){
                    start++;
                }
                else{
                    return sum;
                }
                
                if(abs(sum-target)<diff){
                    ans=sum;
                    diff=abs(sum-target);
                }
            }
        }
        return ans;
    }
};
