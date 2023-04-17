class Solution {
public:
    bool judgeCircle(string moves) {
        int srcx = 0 ; 
        int srcy = 0 ; 

        for (int i = 0 ; i < moves.length() ; i++)
        {
            if (moves[i] == 'R')
            {
                srcx++ ;
            }
            else if (moves[i] == 'L')
            {
                srcx-- ;
            }
            else if (moves[i] == 'U')
            {
                srcy++;
            }
            else
            {
                srcy--; 
            }
        }
        if (srcx == 0 && srcy == 0)
        {
            return true ; 
        }
        return false ; 
    }
};