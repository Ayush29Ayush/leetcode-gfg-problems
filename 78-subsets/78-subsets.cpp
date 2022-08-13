class Solution {
private:
    void subset_finder(vector<int>& nums, int index, vector<int> one_subset, vector<vector<int>> &ans)
    {
        // base case
        if(index>=nums.size())
        {
            ans.push_back(one_subset);
            return;
        }
        // take
        one_subset.push_back(nums[index]);
        subset_finder(nums, index+1, one_subset, ans);
        
        // not take
        one_subset.pop_back();
        subset_finder(nums, index+1, one_subset, ans);
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> one_subset;
        int index = 0;
        subset_finder(nums, index, one_subset, ans);
        
        return ans;
    }
};