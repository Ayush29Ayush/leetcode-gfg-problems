//in case not picking duplicates just sort the given array and then for loop.
class Solution {
public:
    
    void solve(vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int> res,int index,int sum){
        //base case
        if(sum > target){
            return;
        }
        
        if(target == sum){
            ans.push_back(res);
            return;
        }
        
        //else checking for each digit number of possiblities without repeating
        for(int i=index;i<candidates.size();i++){//since for every index the loop will run for n-1 times
            //condition to check that same element is not taken .
            if(i>index && candidates[i] == candidates[i-1]) continue;
            
            //if target becomes less than candidates[i] then all the right side will be no use since this is sorted array.
            if(candidates[i]>target) break;
                
            //recursion call
            res.push_back(candidates[i]);
            solve(candidates,target,ans,res,i+1,sum+candidates[i]);
            
            //backtrack
            res.pop_back();
            
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //for getting lexicographic order we need to sort before recursion.
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        solve(candidates,target,ans,res,0,0);
        return ans;
    }
};