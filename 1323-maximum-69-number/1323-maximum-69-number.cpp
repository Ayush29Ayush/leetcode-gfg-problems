class Solution {
public:
    int maximum69Number (int num) {
        //convert int to string. You can also convert it into vector as per your ease.
        string s = to_string(num);

        //replace 6 with 9 because by changing 9 to 6, we will never get a maximum number, as required in question. COMMON SENSE!!!
        for(auto i=0; i<s.size(); i++){
            if(s[i] == '6'){
                s[i] = '9';
                //break because we are said to change ATMOST one digit
                break;
            }
        }
        //convert string to int
        return stoi(s);
    }
};