class Solution
{
public:
    bool isEqual(int a[26], int b[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2)
    {

        int arr[27] = {0}, arr2[27] = {0}; // declare 2 hashmaps

        int n = s1.length(), m = s2.length(), i = 0, j = n;

        if (n > m) // corner cases
            return false;

        for (int i = 0; i < n; i++) // put s1 in hashmap
            arr[s1[i] - 'a']++;

        while (i < n) // put s2 in hashmap
        {
            arr2[s2[i] - 'a']++;
            i++;
        }

        if (isEqual(arr, arr2)) // if both hashmaps are equal return true
            return true;

        i = 0;
        // otherwise reinitialise i,j and keep adding 1 elemnt from right and removing 1 element from left and keep checking if the hashmaps are equal at any window
        while (j < m && i < m)
        {
            arr2[s2[i] - 'a']--;
            arr2[s2[j] - 'a']++;
            if (isEqual(arr, arr2))
                return true;

            i++;
            j++;
        }

        return false;
    }
};