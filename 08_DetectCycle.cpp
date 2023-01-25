// https://leetcode.com/problems/detect-cycles-in-2d-grid/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j] && dfs(grid, visited, 0, i, j)) return true;
            }
        }
        
        return false;
    }

    bool dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int state, int i, int j){

        if (visited[i][j] == grid[i][j]) return true;
        else visited[i][j] = grid[i][j];

        int m = grid.size(), n = grid[0].size();

        // Go down
        if (state != 3 && i < m-1 && grid[i][j] == grid[i+1][j] && dfs(grid, visited, 1, i+1, j)) return true; 
        // Go right
        if (state != 4 && j < n-1 && grid[i][j] == grid[i][j+1] && dfs(grid, visited, 2, i, j+1)) return true;
        // Go up 
        if (state != 1 && i > 0 && grid[i][j] == grid[i-1][j] && dfs(grid, visited, 3, i-1, j)) return true;
        // Go left
        if (state != 2 && j > 0 && grid[i][j] == grid[i][j-1] && dfs(grid, visited, 4, i, j-1)) return true; 

        return false;
    }
};

class Solution {
    // Create Templates.
public:
    vector<vector<int>> createAdjMatrix(vector<vector<int>> &edges, int &n){
        vector<vector<int>> adj(n+1, vector<int>(n+1, 0));
        for(auto &it: edges){
            // undirected graph
            adj[it[0]][it[1]] = 1;
            adj[it[1]][it[0]] = 1;
        }
        return adj;
    }

    vector<vector<int>> createAdjList(vector<vector<int>> &edges, int &n){
        vector<vector<int>> adj(n+1);
        for(auto &it: edges){
            // udirected graph
            adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }
        return adj;
    }

    vector<int> DFS(vector<vector<int>> &list, int stNode)
    {
        vector<int> visited(list.size(), 0), traversal;
        solveDFS(visited, traversal, list, stNode);
        return traversal;
    }
    void solveDFS(vector<int> &visited, vector<int> &traversal, vector<vector<int>> &list, int node)
    {
    
        traversal.emplace_back(node);
        visited[node] = 1;
    
        for (int i = 0; i < list[node].size(); ++i)
        {
            if (visited[list[node][i]])
                continue;
            else
                solveDFS(visited, traversal, list, list[node][i]);
        }
    }

    vector<int> BFS(int stNode, vector<vector<int>> &list) {
        queue<int> q;
        q.push(stNode);
    
        int n = list.size();
        vector<int> v(n, 0), bfs;
        v[stNode] = 1;
    
        while (q.size()) {
            int node = q.front();
            bfs.emplace_back(node);
    
            for (auto &it: list[node]) {
                if (!v[it]) q.push(it), v[it] = 1;
            }
            q.pop();
        }
        return bfs;
    }

    
    bool containsCycle(vector<vector<char>>& grid) {
        
    }
};

class Solution {
    // Wrong Answer: 
    // [
    //   ["b","a","c"],
    //   ["c","a","c"],
    //   ["d","d","c"],
    //   ["b","c","c"]
    // ]

    // We are not handling the cases properly: 
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j] && dfs(grid, visited, i, j)) return true;
            }
        }
        
        return false;
    }

    bool dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j){

        if (visited[i][j] == grid[i][j]) return true;
        else visited[i][j] = grid[i][j];

        int m = grid.size(), n = grid[0].size();
        // Go down
        if (i < m-1 && grid[i][j] == grid[i+1][j] && dfs(grid, visited, i+1, j)) return true; 
        // Go right
        if (j < n-1 && grid[i][j] == grid[i][j+1] && dfs(grid, visited, i, j+1)) return true; 

        return false;
    }
};

int main () {
    
    return 0;
}
