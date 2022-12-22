// https://leetcode.com/problems/sum-of-distances-in-tree/discuss/695177/Classic-Dp-on-Trees-or-O(n)-time-or-Thoroughly-explained-or-C%2B%2B
class Solution {
	int n;
	vector<list<int>> adjList;
	vector<int> sz, val, ans;

	void dfs1(int node, int par) {

		for (int child : adjList[node]) {
			if (child != par) {
				dfs1(child, node);
				sz[node] += sz[child];
				val[node] += val[child] + sz[child];
			}
		}
		sz[node]++;
	}

	void dfs2(int node, int par, int dpVal) {
		ans[node] = val[node] + dpVal + (n - sz[node]);

		for (int child : adjList[node]) {
			if (child != par)
				dfs2(child, node, ans[node] - val[child] - sz[child]);
		}
	}
    
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		n = N;
		adjList.resize(n), sz.resize(n), val.resize(n), ans.resize(n);
		for (vector<int> &v : edges) {
			adjList[v[0]].push_back(v[1]);
			adjList[v[1]].push_back(v[0]);
		}
		dfs1(0, 0);
		dfs2(0, 0, 0);
		return ans;
	}
};