// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/discuss/2754088/PythonC%2B%2BJavaRust-intuitive-VISUAL-and-concise-calculation-of-time-(with-detailed-comments)
class Solution 
{
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        vector<pair<int, int>> pairs;
        for (auto i = 0; i < plantTime.size(); ++i)
            pairs.emplace_back(growTime[i], plantTime[i]);
        
        // nice trick with reverse iterators for reverse sorting
        sort(pairs.rbegin(), pairs.rend());
        
        int c = 0, t = 0;
        for (auto[g,p] : pairs) { c += p; t = max(t, c + g); }
        
        return t;
    }
};