class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int counter = 0;
        for(int i = 0; i < arr.size()-1; i++)
        {
            if(arr[i] > arr[i+1]){
                if(counter == 1)
                    return false;
                if(i == 0 || (arr[i+1] >= 0 && arr[i+1] >= arr[i-1]))
                    arr[i] = arr[i+1];
                else
                    arr[i+1] = arr[i]+1;
                counter++;
            }
        }
        return true;
    }
};