class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int num_of_ones = 0;
        int changes = 0;
        
        for(auto c : s)
        {
            if(c=='0')
            {
                if(num_of_ones==0)
                {
                    // do nothing
                }
                else
                {
                    changes++;
                }
            }
            else
            {
                num_of_ones++;
            }
            changes = min(changes, num_of_ones); // either changes all 1 or all 0
        }
        
        return changes;
    }
};