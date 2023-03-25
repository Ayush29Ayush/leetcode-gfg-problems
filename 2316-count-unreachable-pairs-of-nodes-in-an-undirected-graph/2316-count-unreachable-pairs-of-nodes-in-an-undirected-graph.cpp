class Solution{
public:
    void DFS(int node, vector<vector<int>> &Adj, vector<bool> &visited, long long int &size){
        size++;
        visited[node] = 1;
        for (auto &i : Adj[node]){
            if (!visited[i]){
                DFS(i, Adj, visited, size);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>> &edges){
        vector<vector<int>> Adj(n);
        
        for (auto &edge1 : edges){
            Adj[edge1[0]].push_back(edge1[1]);
            Adj[edge1[1]].push_back(edge1[0]);
        }
        
        vector<long long int> v;
        vector<bool> visited(n, false);
        long long int summation = 0;
        
        for (int i = 0; i < n; i++){
            if (!visited[i]){
                long long int size = 0;
                DFS(i, Adj, visited, size);
                v.push_back(size);
                summation += size;
            }
        }
        
        long long int answer = 0;
        for (int i = 0; i < v.size(); i++){
            summation -= v[i];
            answer += v[i] * summation;
        }
        
        return answer;
    }
};