class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        // int mini = *min_element(arr,arr+n);
        // int maxi = *max_element(arr,arr+n);
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