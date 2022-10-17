//concept is that we simply check for left to right falling dominoes and after how much time it will affect left to right , ||ly we check for right to left and then traverse finally and check for whose values is less means that will affect the . domino first.
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left_right(n,0),right_left(n,0);
        
        char prev = '.';
        int count = 1;
        for(int i=0;i<n;i++){
            if(dominoes[i] == 'R'){
                prev = 'R';
                //check the effect of R to the right.
                count = 1;
                continue;
            }
            else if(dominoes[i] == 'L'){
                prev = 'L';
            }
            
            if(prev == 'R' && dominoes[i] == '.'){
                left_right[i] = count++;
            }
        }
        //||ly check for right_left effect.
        prev = '.';
        count = 1;
        for(int i=n-1;i>=0;i--){
            if(dominoes[i] == 'L'){
                prev = 'L';
                count = 1;
                continue;
            }
            else if(dominoes[i] == 'R'){
                prev = 'R';
            }
            
            if(prev == 'L' && dominoes[i] == '.'){
                right_left[i] = count++;
            }
        }
        
        //now check for final affect .
        string ans = "";
        for(int i=0;i<n;i++){
            if(left_right[i] == 0 && right_left[i] == 0){
                ans += dominoes[i];
            }
            else if(left_right[i] == 0 && right_left[i] != 0){
                ans += 'L';
            }
            else if(left_right[i] != 0 && right_left[i] == 0){
                ans += 'R';
            }
            else if(left_right[i] == right_left[i]){
                ans += '.';
            }
            else if(left_right[i] < right_left[i]){
                //to wo store karo jo min ho kyunki vo phele effect dalega.
                ans += 'R';
            }
            else{
                ans += 'L';
            }
        }
        return ans;
    }
};