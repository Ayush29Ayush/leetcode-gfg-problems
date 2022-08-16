// https://www.youtube.com/watch?v=RIn3gOkbhQE&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=11

//in case of not picking duplicates just sort the given array and then go for loop this will avoid duplicates.
class Solution {
public:
    
    void solve(vector<int>& nums,vector<vector<int>> &ans,vector<int> res,int index){
        //base case
        ans.push_back(res);
        
        //for loop for picking elements.
        for(int i=index;i<nums.size();i++){
            //avoid picking duplicate
            if(i>index && (nums[i] == nums[i-1]))
                continue;
            res.push_back(nums[i]);
            //recursive call
            solve(nums,ans,res,i+1);
            //backtrack
            res.pop_back();
                
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        //need to sort to avoid repeat
        sort(nums.begin(),nums.end());
        solve(nums,ans,res,0);
        return ans;    
    }
};