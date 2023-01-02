class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long masss = mass;
        
        for(int i=0; i<asteroids.size(); i++)
        {
            if(masss-asteroids[i]<0)
                return false;
            else
                masss+=asteroids[i];
        }
        return true;
    }
};