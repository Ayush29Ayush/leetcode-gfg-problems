class BrowserHistory {
private:
    vector<string> history;
    int idx = 0, end = 0;
public:
    BrowserHistory(string homepage) {   
        history.push_back(homepage);
    }
    
    void visit(string url) {
        end = ++idx;
        
        if (idx < history.size())
            history[idx] = url;
        else
            history.push_back(url);
    }
    
    string back(int steps) {
        idx = max(idx - steps, 0);
        return history[idx];
    }
    
    string forward(int steps) {
        idx = min(idx + steps, end);
        return history[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */