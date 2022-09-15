// https://leetcode.com/problems/find-original-array-from-doubled-array/discuss/2577700/C%2B%2B-or-HashmapSorting(NlogN)-Approach

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        // if size is odd means one element more or less so it isn't a doubled array
        if (n % 2 == 1) return {};
        
        //! Step1 : First we take a map, then we sort the given array changed.
        map<int, int> mp;
        sort(changed.begin(), changed.end());
        
        vector<int> ans;
        
        //! Step2 : Count the freq of each element in changed array and store a key-value pair
        for (int i = 0; i < n; i++) {
            mp[changed[i]]++;
        }
        
        //! Step3 : 
        for (int i = 0; i < n; i++) {
            
          // kahi pehle hi iss element ke kaam karke freq 0 naa kardi ho check karo, if true then skip and go to next iteration
          if (mp[changed[i]] == 0) continue;
          // check if element ke double ki freq 0 toh nahi ho gayi. Ex-> [1,1,2,3] yahan ek iteration ke baad double ki freq 0 ho jayegi so jab second time 1 pe ayenge toh double ki freq 0 milegi
            
          // since changed is sorted, the only pair we can make for changed[i] is changed[i] * 2. Therefore, if the count of the target pair is 0, we couldn't make the pair, then we return {}.
          if (mp[changed[i] * 2] == 0) return {};
            
          // if upar ke dono cases true nahi hue that means ki doubled array ka format follow ho raha hai 
          ans.push_back(changed[i]);
          // element and uske double ki freq minus 1 kardo
          mp[changed[i]]--;
          mp[changed[i] * 2]--;
        }
        return ans;
    }
};