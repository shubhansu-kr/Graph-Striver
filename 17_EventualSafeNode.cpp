// https://leetcode.com/problems/find-eventual-safe-states/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> dp(n, -1), vis(n), path(n), ans;

        for (int i = 0; i < n; ++i)
        {
            if (!vis[i]) dp[i] = dfs(graph, dp, vis, path, i);
        }
        
        for (int i = 0; i < n; ++i)
        {
            if (dp[i]) ans.emplace_back(i);
        }
        
        return ans;
    }

    int dfs(vector<vector<int>> &graph, vector<int> &dp, vector<int> &vis, vector<int> &path, int i){
        if (path[i]) return 0;

        // Return the value if already visited.
        if (dp[i] != -1) return dp[i];

        path[i] = 1;
        vis[i] = 1;

        int temp = 1;
        for(auto &it: graph[i]) {
            temp &= dfs(graph, dp, vis, path, it);
        }

        path[i] = 0;

        return dp[i] = temp;
    }
};

int main () {
    
    return 0;
}