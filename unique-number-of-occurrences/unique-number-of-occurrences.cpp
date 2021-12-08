class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        for(int x: arr){
            mp[x]+=1; // update the frequency each time
        }
        
        set<int>st;
        for(auto it : mp){
            // count() returns 1 is value is present else 0
            // see this http://www.cplusplus.com/reference/set/set/count/
            if(st.count(it.second)>0)
                return false;
            else st.insert(it.second);
        }
        return true;
    }
};