class Solution {
private:
    bool checkEqual(int a[26], int b[26]){
        for(int i = 0; i<26; i++){
            if(a[i]!=b[i]){
                return false;   //if any char not match, return false
            }
        }
    return true;    //everything passed if you made it out of loop :)
    }
    
public:
    bool checkInclusion(string s1, string s2) {
        //character count array store
        int count1[26] = {0};
        
        for(int i = 0; i<s1.length(); i++){
            int index = s1[i]-'a';  //get the index of the char in the alphabet count array and do compare and check in sliding window appraoch
            count1[index]++;
        }
        
        
        //traverse s2 string with the sliding window length of s1.length() and compare
        //running window
        int i = 0;
        int count2[26] = {0};
        int windowSize = s1.length();
        
        //running on first window => here first 2 chars of s2 will come here and then we will compare in is Equal function if not => move ahead
        while(i<windowSize && i<s2.length()){   //check if window moves ahead of length of 2nd string => that's why additional condition
            int index = s2[i]-'a';
            count2[index]++;
            i++;
        }
        
        //check if the elements in window is permutation of s1
        
        if(checkEqual(count1,count2)){
            //true means we got the permutation
            return true;
        }
        else{   //keep window processing ahead, shifting and checking & ++ the new char and -- the old char in window to maintain correct count
            
            while(i<s2.length()){
                char newElement = s2[i];
                int index = newElement - 'a';   //we got index of new element now ++ it
                count2[index]++;
                //remove oldElement from window
                char oldElement = s2[i-windowSize];
                index = oldElement - 'a';   //get index of the old char and --
                count2[index]--;
                i++; //loop count
                
                //do maintain a check are these equal now or what 
                if(checkEqual(count1,count2)){
                return true;
                }
                
            }   
        }
        //if you break out of loop and not return true => then it can't be equal
                return false;
    }    
        
};