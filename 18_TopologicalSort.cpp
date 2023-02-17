// Topological Sort

#include <bits/stdc++.h>
using namespace std ;

class Solution
{
    // Using bfs
public: 
    vector<int> topologicalSort(vector<vector<int>> &edges, int &n) {
        // Create adj list 
        vector<vector<int>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].emplace_back(it[1]);
        }
        
        vector<int> vis(n);
        stack<int> temp;

        for (int i = 0; i < n; ++i)
        {
            if (vis[i]) continue;
            bfs(adj, temp, vis, i);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = temp.top();
            temp.pop();
        }
        
        return ans;
    }

    void bfs(vector<vector<int>> &adj, stack<int> &temp, vector<int> &vis, int i){
        queue<int> q;

        q.push(i);
        vis[i] = 1;

        while(q.size()) {
            int top = q.front();
            q.pop();

            temp.push(top);

            for(auto &it: adj[top]) {
                if (vis[it]) continue;
                q.push(it);
                vis[it] = 1;
            }
        }

        return;
    }
};

class Solution
{
    // Using dfs
public: 
    vector<int> topologicalSort(vector<vector<int>> &edges, int &n) {
        // Create adj list 
        vector<vector<int>> adj(n);
        for(auto &it: edges) {
            adj[it[0]].emplace_back(it[1]);
        }
        
        vector<int> vis(n);
        stack<int> temp;

        for (int i = 0; i < n; ++i)
        {
            if (vis[i]) continue;
            dfs(adj, temp, vis, i);
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = temp.top();
            temp.pop();
        }
        
        return ans;
    }

    void dfs(vector<vector<int>> &adj, stack<int> &temp, vector<int> &vis, int i){
        stack<int> st;

        st.push(i);
        vis[i] = 1;

        while(st.size()) {
            int top = st.top();
            st.pop();

            temp.push(top);

            for(auto &it: adj[top]) {
                if (vis[it]) continue;
                st.push(it);
                vis[it] = 1;
            }
        }

        return;
    }
};

int main () {
    
    return 0;
}