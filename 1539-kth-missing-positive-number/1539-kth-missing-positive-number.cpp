// the highest number in the array can be 1000 and the highest k can be 1000,then the loop should run from 1 to 2000.
// manlo ki arr mein 1 se 1000 tak sab elements present hai and k=1000th missing element maang raha hai toh kya karoge
// isiliye 1000+1000=2000 tak loop chalega 

// Brute Force 1
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        // int mini = *min_element(arr,arr+n);
        // int maxi = *max_element(arr.begin(),arr.end());
        vector<int> missing;
        set<int> s;
        
        for(int i=0; i<arr.size(); i++)
            s.insert(arr[i]);
        
        for(int i=1; i<=2000; i++)
        {
            // agar koi position nahi mila uss element ka that means ki voh hai hi nahi set mein
            if(s.find(i)==s.end())
                missing.push_back(i);
        }
        
        return missing[k-1];
    }
};

// Brute Force 2
// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         vector<int> temp(2001); // by default value 0 hoga pure vector mein
        
//         // jitne present hai arr mein unki value 0 se ab 1 ho jayega
//         for(auto value : arr)
//             temp[value]++;
        
//         int count=0;
//         for(int i=1; i<=2000; i++)
//         {
//             // value 0 means missing number hai so start counting those numbers
//             if(temp[i]==0)
//                 count++;
            
//             if(count==k)
//                 return i;
//         }
        
//         return -1;            
//     }
// };