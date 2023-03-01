class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        
        if(n<3){
            return nums[n-1];
        }
        
        int count = 1;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]!=nums[i])
                count++;
            if(count==3)
                return nums[i];
        }
        
        return nums[n-1];
    }
};