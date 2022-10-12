// Sort the array
// Apply the geometry principe of triangle "The sum of the length of the two sides of a triangle is greater than the length of the third side" A<B+C
// Do the reverse iteration.
// Apply these logic nums[i] + nums[i+1]>nums[i+2]
// nums[i] + nums[i+1]>nums[i+2] if it is true then return nums[i] + nums[i+1] + nums[i+2]
// else return 0

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
    
        sort(nums.begin(), nums.end());                 //sort the array

        for(int i=nums.size()-3; i>=0; i--){            //traverse from n-3 to 0
            if(nums[i]+nums[i+1] > nums[i+2]) {         //if at any instant a + b > c, return perimenter (a+b+c)
                return  nums[i]+nums[i+1]+nums[i+2];    // a=nums[i], b=nums[i+1], c=nums[i+2];
            }
        }
        return 0;                                       //else return 0
    }
};