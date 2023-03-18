class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int num = 0;
        for(auto jewel : jewels)
            for(auto stone : stones)
                if(stone==jewel)
                    num++;
        
        return num;
    }
};