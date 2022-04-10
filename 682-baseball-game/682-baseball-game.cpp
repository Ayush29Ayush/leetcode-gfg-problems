class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        for (string ch : ops) {
            if (ch == "C")
                record.pop_back();
            else if (ch == "D")
                record.push_back(record.back() * 2);
            else if (ch == "+")
                record.push_back(record.back() + record[record.size() - 2]);
            else
                record.push_back(stoi(ch)); // stoi means string to integer
        }
        
        return accumulate(record.begin(), record.end(), 0); // accumulate returns the sum of all the elements
    }
};