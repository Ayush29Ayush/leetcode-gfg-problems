class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count=0;
        unordered_map<int,int> freq;
        
        for(int i=0;i<answers.size();i++){
		//If the frequency of same color rabbits is 0,
		//then we have a unique coloured rabbit and we will directly count it
            if(answers[i]==0) count++;
            else{
                freq[answers[i]]++;
            }
        }
        
        for(auto it:freq){
            count= count + (it.first+1)*ceil(((float)it.second/(it.first+1)));
        }
        
        return count;
    }
};