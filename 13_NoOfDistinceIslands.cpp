// https://leetcode.com/problems/number-of-distinct-islands/

// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

// Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands 
// where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered 
// to be distinct if and only if one island is not equal to another (not rotated or reflected).


#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Wrong Answer
    // 2 5
    // 1 0 1 1 0
    // 1 1 1 0 0
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here

        // cout << "Flag1\n";
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int> (n, 0));
        int counter = 0;
        unordered_set<long long> _set;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] && !vis[i][j]){
                    // cout << "Flag2\n";
                    long long x = traverse(grid, vis, m, n, i, j);
                    // cout << x << endl;
                    if (!_set.count(x)) {
                        _set.insert(x);
                        counter++;
                    }
                }
            }
        }
        return counter;
    }

    long long traverse(vector<vector<int>> &grid, vector<vector<int>> &vis, int &m, int &n, int &i, int &j){
        int rowShift[] = {0, +1, 0, -1}, colShift[] = {+1, 0, -1, 0}, nRow, nCol;
        queue<pair<int, int>> q;
        // cout << i << " " << j << "\n";
        q.push({i, j});
        vis[i][j] = 1;

        long long sum = 1;
        while(q.size()){
            
            pair<int, int> pt = q.front();
            q.pop();
            // cout << "Flag3 ";
            int r = pt.first, c = pt.second;
            // cout << r << " " << c << endl;
            

            for (int k = 0; k < 4; ++k)
            {
                nRow = r + rowShift[k], nCol = c + colShift[k];
                if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n) {
                    
                    if (grid[nRow][nCol] && !vis[nRow][nCol]) {
                        vis[nRow][nCol] = 1;
                        q.push({nRow, nCol});

                        if (k == 0) sum += 41;
                        else if (k == 1) sum += 11;
                        else if (k == 2) sum += 31;
                        else sum += 71;
                    }
                }
            }

        }
        // cout << "\nSum: " << sum << endl;
        return sum;
    }

};

int main () {
    vector<vector<int>> grid = {{1, 1, 0, 0, 0}, 
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};

    Solution Obj1;
    // cout << Obj1.countDistinctIslands(grid);

    return 0;
}