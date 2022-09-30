class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        
        vector<int> pos(n,n-1);
        
        for(int i = n-2; i>=0; i--)
        {
            if(s[i]>s[pos[i+1]])
                pos[i] = i;
            else
                pos[i] = pos[i+1];
        }
        
        // to find the element jiske saath swap karna hai 
        int i = 0;
        while(i<n && s[i] >= s[pos[i]])
            i++;
        
        // agar range mein hai then swap
        if(i<n)
            swap(s[i],s[pos[i]]);
        
        int ans = stoi(s);
        return ans;
        
    }
};
