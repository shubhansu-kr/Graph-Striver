// https://leetcode.com/problems/number-of-islands/

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Optimise 
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    ++count;
                    DFS(grid, i, j);
                }
            }
        }
        return count;
    }
    void DFS(vector<vector<char>> &grid, int i, int j)
    {
        grid[i][j] = '0';
        if (i < grid.size()-1 && grid[i+1][j] == '1' ) {  
            DFS(grid, i+1, j); 
        }
        if (i > 0 && grid[i-1][j] == '1' ) {  
            DFS(grid, i-1, j); 
        }
        if (j < grid[0].size()-1 && grid[i][j+1] == '1' ){
            DFS(grid, i, j+1);
        }
        if (j > 0 && grid[i][j-1] == '1' ){
            DFS(grid, i, j-1);
        }
        return ;
    }
};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    ++count;
                    DFS(grid, visited, i, j);
                }
            }
        }
        return count;
    }
    void DFS(vector<vector<char>> &grid, vector<vector<int>> &visited, int i, int j)
    {
        visited[i][j] = 1;
        if (i < grid.size()-1 && grid[i+1][j] == '1' && !visited[i+1][j]) {  
            DFS(grid, visited, i+1, j); 
        }
        if (i > 0 && grid[i-1][j] == '1' && !visited[i-1][j]) {  
            DFS(grid, visited, i-1, j); 
        }
        if (j < grid[0].size()-1 && grid[i][j+1] == '1' && !visited[i][j+1]){
            DFS(grid, visited, i, j+1);
        }
        if (j > 0 && grid[i][j-1] == '1' && !visited[i][j-1]){
            DFS(grid, visited, i, j-1);
        }
        return ;
    }
};

// [
// ["1","0","1","1","1"],
// ["1","0","1","0","1"],
// ["1","1","1","0","1"]
// ]

int main()
{

    return 0;
}