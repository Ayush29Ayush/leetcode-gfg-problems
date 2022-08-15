class Solution {
public:
    void solve(int index, int target, vector<int> &candidates , vector<int> &ds, vector<vector<int>> &ans)
    {
        // base case
        if(index==candidates.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        
        //if it picks then it has two options => pick the same element again or don't pick that element and go to next index.
        //pick the element
        if(candidates[index]<=target)
        {
            ds.push_back(candidates[index]);
            //recursive call to pick the element
            solve(index, target-candidates[index], candidates, ds, ans);
            
            //after returning to this recursive state, remove the last added element.
            ds.pop_back();
        }
        
        // not pick the element
        solve(index+1, target, candidates, ds, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(0, target, candidates, ds, ans);
        
        return ans;
    }
};