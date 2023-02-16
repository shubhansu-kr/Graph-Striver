// https://leetcode.com/problems/course-schedule-ii/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // DFS Topological sort
public:

    vector<vector<int>> createAdjList(vector<vector<int>> &edges, int &n){
        vector<vector<int>> adj(n+1);
        for(auto &it: edges){
            adj[it[1]].emplace_back(it[0]);
        }
        return adj;
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj = createAdjList(edges, n);

        vector<int> path(n), vis(n), ans;
        for (int i = 0; i < n; ++i)
        {
            if (!vis[i] && !dfs(adj, vis, path, ans, i)) return vector<int>({});
        }
        
        return ans;
    }

    bool dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &path, vector<int> &ans, int i){
        if (path[i]) return false;
        if (vis[i]) return true;

        path[i] = 1;
        vis[i] = 1;

        for(auto &it: adj[i]) {
            if (!dfs(adj, vis, path, ans, it)) return false;
        }

        path[i] = 0;
        ans.insert(ans.begin(), i);

        return true;
    }
};

int main () {
    
    return 0;
}