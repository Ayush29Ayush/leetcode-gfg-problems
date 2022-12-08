class Solution {
public:
    int minMovesToMakePalindrome(string s) {
       int n = s.length();
       int i =0,j=n-1;
        int ans = 0;
        while(i<j){
            if(s[i]==s[j]){     // Both Characters are same move 2 pointers
                i++;
                j--;
            }else{
			// Both characters are not same
                int found = -1;
				//find index nearest to j which matches with i index
                for(int k=j-1;k>i;k--){
                    if(s[k]==s[i]){
                        found = k;
                        break;
                    }
                }
                
				// found the character which is equal to s[i]
                if(found>0){
                    for(int k=found;k<j;k++){
                        swap(s[k],s[k+1]);
                        ans++;
                    }
                    i++;
                    j--;
                }else{
				/* If not found means that character at ith index would have been odd character.
				so swap it so it would eventually end at middle of string*/
                    swap(s[i],s[i+1]);
                    ans++;
                }
                
            }
        }
        return ans;
    }
};