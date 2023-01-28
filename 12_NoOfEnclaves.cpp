// https://leetcode.com/problems/number-of-enclaves/

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another adjacent (4-directionally) land 
// cell or walking off the boundary of the grid.

// Return the number of land cells in grid for which we cannot walk off the boundary of the 
// grid in any number of moves.

#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        stack<pair<int, int>> st;
        int m = grid.size(), n = grid[0].size();

        // Pick each land cell from first and last row.
        for (int j = 0; j < n; ++j)
        {
            if(grid[0][j]) {
                st.push({0, j});
                grid[0][j] = 0;
            }

            // Check if the last row is same as first row.
            if (m > 1) {
                if (grid[m-1][j]){
                    st.push({m-1, j});
                    grid[m-1][j] = 0;
                }
            }
        }
        
        // Pick land cells from first and last column
        for (int i = 1; i < m-1; ++i)
        {
            if (grid[i][0]) {
                st.push({i, 0});
                grid[i][0] = 0;
            }
            
            // Check if first and last col are same.
            if (n > 1){
                if (grid[i][n-1]){
                    st.push({i, n-1});
                    grid[i][n-1] = 0;
                }
            }
        }
        
        // While all the connected land cells are flipped
        while(st.size()) {
            pair<int, int> p = st.top();
            st.pop();

            int r = p.first, c = p.second, nRow, nCol;

            int rowShift[] = {-1, 0, +1, 0}, colShift[] = {0, -1, 0, +1};

            for (int i = 0; i < 4; ++i)
            {
                nRow = r + rowShift[i];
                nCol = c + colShift[i];

                // Check for valid neighbour cell.
                if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n) {
                    if (grid[nRow][nCol]) st.push({nRow, nCol}), grid[nRow][nCol] = 0;
                }
            }
        }

        // Simply count the remaining 1's
        int ans = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j]) ++ans;
            }
        }
        
        return ans;
    }
};


int main () {
    
    return 0;
}