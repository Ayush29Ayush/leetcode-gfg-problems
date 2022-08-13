// void subset_finder(vector<int>& nums, int index, vector<int> one_subset, vector<vector<int>> ans)
//     {
//         // base case
//         if(index>=nums.size())
//         {
//             ans.push_back(one_subset);
//             return;
//         }
//         // take
//         one_subset.push_back(nums[index]);
//         subset_finder(nums, index+1, one_subset, ans);
        
//         // not take
//         one_subset.pop_back();
//         subset_finder(nums, index+1, one_subset, ans);
//     }
    
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         vector<int> one_subset;
//         int index = 0;
//         subset_finder(nums, index, one_subset, ans);
        
//         return ans;
//     }

class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans) {
        //base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(nums, output, index+1, ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
        
    }
};