// https://leetcode.com/problems/shortest-distance-to-a-character/discuss/2173687/C%2B%2B-solution-oror-Simple-oror-Easy-understanding

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> position;
        vector<int> answer;
        
        //collect all the position of given char
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]==c)
                position.push_back(i);
        }
        //traverse and find the shortest distance(min difference) from the given char to all given positions
        for(int i=0; i<s.size(); i++)
        {
            int shortest_dist = INT_MAX;
            for(int j=0; j<position.size(); j++)
            {
                shortest_dist = min(shortest_dist, abs(i-position[j]));
            }
            answer.push_back(shortest_dist);
        }
        
        return answer;
    }
};