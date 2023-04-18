class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxcount=0;
        int index=0;
        // go to every row
        for(int i=0;i<mat.size();i++){
            int countone=0;
            // next row pe jaane se pehle counter ko 0 kardo
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    countone++;
                }
            }
            // max ko update kardo if greater count acquired
             if(countone>maxcount){
                 maxcount=countone;
                index=i;
             }
        }
        // return row,count 
        return {index,maxcount};
    }
};