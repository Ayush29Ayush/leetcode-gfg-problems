class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');

        vector<int> nums(words.size());
        
        for(int i=0;i<words.size();i++){
            int start=0, end=words[i].size()-1;
            if(vowels.count(words[i][start])>0 && vowels.count(words[i][end])>0) nums[i]=1;
            else nums[i]=0;
        }

        //Evaluate prefix sum 
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]+nums[i-1];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];

            if(start==0){
                ans.push_back(nums[end]);
            }
            else{
                ans.push_back(nums[end]-nums[start-1]);
            }
        }
        return ans;

    }
};