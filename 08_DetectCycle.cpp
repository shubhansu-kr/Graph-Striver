// https://leetcode.com/problems/detect-cycles-in-2d-grid/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Wrong Answer: 
    // [
    //   ["b","a","c"],
    //   ["c","a","c"],
    //   ["d","d","c"],
    //   ["b","c","c"]
    // ]
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j] && dfs(grid, visited, grid[i][j], i, j)) return true;
            }
        }
        
        return false;
    }

    bool dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, char &val, int i, int j){

        if (visited[i][j] == val) return true;
        else visited[i][j] = val;

        int m = grid.size(), n = grid[0].size();
        // Go down
        if (i < m-1 && grid[i][j] == grid[i+1][j] && dfs(grid, visited, val, i+1, j)) return true; 
        // Go right
        if (j < n-1 && grid[i][j] == grid[i][j+1] && dfs(grid, visited, val, i, j+1)) return true; 

        return false;
    }
};

int main () {
    
    return 0;
}
