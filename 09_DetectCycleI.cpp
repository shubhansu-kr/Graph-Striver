// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution1
{    
    // DFS: Solution with stack: WA: How to track the previous state.
public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V);
        stack<int> st;
        for (int i = 0; i < V; ++i)
        {
            if(!visited[i]){
                st.push(i);
                while(st.size()){
                    int top = st.top();
                    st.pop();

                    if (visited[top]) return true;
                    visited[top] = 1;

                    for(auto &it: adj[top]){
                        st.push(it);
                    }
                }
            }
        }
        return false;
    }
};

class Solution
{    
    // DFS: Solution with recursion
public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V);
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i] && dfs(adj, visited, -1, i)) return true; 
        }
        return false;
    }

    bool dfs(vector<int> adj[], vector<int> &visited, int prev, int i){
        if (visited[i]) return true;

        visited[i] = 1;
        for(auto &it: adj[i]) {if (it != prev && dfs(adj, visited, i, it)) return true;} 
    
        return false;
    }
};

class Solution
{
    // Wrong Answer: 
    // 4 2
    // 1 2
    // 2 3

    // Constraint the previous state.
public:
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> visited(V);
        for (int i = 0; i < V; ++i)
        {
            if (!visited[i] && dfs(adj, visited, i)) return true; 
        }
        return false;
    }

    bool dfs(vector<int> adj[], vector<int> &visited, int i){
        if (visited[i]) return true;

        visited[i] = 1;
        for(auto &it: adj[i]) if (dfs(adj, visited, it)) return true;
    
        return false;
    }
};

int main()
{

    return 0;
}