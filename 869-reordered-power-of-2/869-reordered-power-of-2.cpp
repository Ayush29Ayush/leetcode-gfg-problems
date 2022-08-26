// https://leetcode.com/problems/reordered-power-of-2/discuss/2481795/Easy-solution-Explained-oror-Beginner-Friendly-oror-Best-Method

class Solution {
public:
    bool reorderedPowerOf2(int n) {
       string given = to_string(n);
        sort(given.begin(), given.end());
        
        for(int i = 0; i < 30;i++){
            string temp = to_string(1 << i);
            sort(temp.begin(), temp.end());
            if(given == temp){
                return true;
            }
        }
        return false;
    }
};