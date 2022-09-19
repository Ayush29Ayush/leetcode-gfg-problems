class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
          
        vector<vector<int>> vec;
  
        // sort the array
        sort(nums.begin(),nums.end());
    
        for(int i=0;i<nums.size();i++)
        {
            // if duplicate is found, go to next element
            if(i>0 && nums[i]==nums[i-1])
                continue;
            
            // using 2 pointer approach here
            int start = i+1;
            int end = nums.size()-1;

            while(start<end)
            {
                if(nums[i]+nums[start]+nums[end]==0)
                {
                    // main objective
                    vec.push_back( {nums[i],nums[start],nums[end]} );
                    start++;
                    end--;
                }
                // increment start pointer if sum<0 and if vica-versa then decrement the end pointer
                else if(nums[i]+nums[start]+nums[end]<0)
                    start++;
                else if(nums[i]+nums[start]+nums[end]>0)  
                    end--;
            }
        }
        // to remove duplicates use stl approach
        sort( vec.begin(), vec.end() );
        vec.erase( unique( vec.begin(), vec.end() ), vec.end() );


        return vec;
    }
};