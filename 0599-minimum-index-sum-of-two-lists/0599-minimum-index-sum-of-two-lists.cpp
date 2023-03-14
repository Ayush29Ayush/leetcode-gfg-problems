class Solution
{
    public:
        vector<string> findRestaurant(vector<string> &a, vector<string> &b)
        {
            vector<string> ans;
            int min = INT_MAX;
            for (int i = 0; i < a.size(); i++)
            {
                for (int j = 0; j < b.size(); j++)
                {
                    if (a[i] == b[j])
                    {
                        if (i + j < min)
                        {
                            min = i + j;
                            ans.clear();
                            ans.push_back(a[i]);
                        }
                        else if (i + j == min)
                        {
                            ans.push_back(a[i]);
                        }
                    }
                }
            }
            return ans;
        }
};