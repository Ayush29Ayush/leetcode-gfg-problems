class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int j = s.length()-1;
        int i=0,flag=0;
        while(i<j){
            if(s[i]==s[j]){
                flag=1;
            }
            else{
                flag=0;
                return false;
                break;
            }
            i++;
            j--;
        }
        return true;
    }
};