//!Brute Force Approach:
class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums){
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            ans[i] = -1;
            for (int j = 1; j < n; j++){
                if (nums[i] < nums[(i + j) % n]){
                    ans[i]= nums[(i + j) % n];
                    break;
                }
            }
        }
        return ans;
    }

};

