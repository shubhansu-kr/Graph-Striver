// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution1 {
    // BFS solution with queue. 
    // Use pairs to store the prev/origin node
public: 
    bool isCycle(int V, vector<vector<int>> &adj){
        vector<int> visited(V+1);
        queue<pair<int, int>> q;

        // Run through each distinct connections.
        for (int i = 1; i <= V; ++i)
        {  
            if (visited[i]) continue;

            int cur, prev;
            q.push({i, -1}); // unvisited node

            while(q.size()){
                cur = q.front().first;
                prev = q.front().second;

                q.pop();

                visited[cur] = 1;

                for(auto &it: adj[cur]){
                    if (it == prev) {continue;}
                    else {
                        if (visited[it]) return true;
                        else q.push({it, cur});
                    }
                }
            }
        }
        return false;
    }
};


// ERROR: LOGIC: When two nodes are connected to one node, we loose the prev track. 
// class Solution
// {   
//     // Segmentation Fault: RE
//     // BFS: Solution with Queue.
// public:
//     bool isCycle(int V, vector<vector<int>> &adj){
//         vector<int> visited(V+1);

//         // Run through each distinct connections.
//         for (int i = 1; i <= V; ++i)
//         {  
//             if (visited[i]) continue;

//             queue<int> q;
//             int prev = -1, cur;
//             q.push(i); // unvisited node

//             while(q.size()){
//                 cur = q.front();
//                 q.pop();

//                 visited[cur] = 1;

//                 for(auto &it: adj[cur]){
//                     if (it == prev) {
//                         // skip
//                     }
//                     else {
//                         if (visited[it]) return true;
//                         else q.push(it);
//                     }
//                 }
//                 prev = cur;
//             }
//         }
//         return false;
//     }
// };

// LogicalError: 
// class Solution
// {
//     // DFS: Solution with stack: WA: How to track the previous state.
// public:
//     bool isCycle(int V, vector<int> adj[])
//     {
//         vector<int> visited(V);
//         stack<int> st;
//         for (int i = 0; i < V; ++i)
//         {
//             if (!visited[i])
//             {
//                 st.push(i);
//                 while (st.size())
//                 {
//                     int top = st.top();
//                     st.pop();

//                     if (visited[top]) return true;
//                     visited[top] = 1;

//                     for (auto &it : adj[top]) {st.push(it);}
//                 }
//             }
//         }
//         return false;
//     }
// };

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

    bool dfs(vector<int> adj[], vector<int> &visited, int prev, int i)
    {
        if (visited[i]) return true;

        visited[i] = 1;
        for (auto &it : adj[i]) { if (it != prev && dfs(adj, visited, i, it)) return true; }

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
        for (int i = 0; i < V; ++i) { if (!visited[i] && dfs(adj, visited, i)) return true; }
        return false;
    }

    bool dfs(vector<int> adj[], vector<int> &visited, int i)
    {
        if (visited[i]) return true;

        visited[i] = 1;
        for (auto &it : adj[i]) if (dfs(adj, visited, it)) return true;

        return false;
    }
};

int main()
{

    vector<vector<int>> adj;

    return 0;
}