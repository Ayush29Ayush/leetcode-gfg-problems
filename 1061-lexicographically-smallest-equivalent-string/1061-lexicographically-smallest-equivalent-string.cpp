class Solution {
public:
    int root[26];
    
    // recursively get the root element
    int get(int x) {
        return x == root[x] ? x : (root[x] = get(root[x]));
    }
    
    // unite two elements
    void unite(int x, int y) {
        // find the root of x
        x = get(x);
        // find the root of y
        y = get(y);
        // if their roots are not same, we combine them
        if (x != y) {
            // smaller first
            if (x < y)  root[y] = x;
            else root[x] = y;
        }
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // dsu
        string ans;
        // init root. initialy each element is in its own group.
        for (int i = 0; i < 26; i++)  root[i] = i;
        // unite each character
        for (int i = 0; i < s1.size(); i++) unite(s1[i] - 'a', s2[i] - 'a');
        // build the final answer from the root element (smallest)
        for (auto x : baseStr) ans += (char)(get(x - 'a') + 'a');
        return ans;
    }
};