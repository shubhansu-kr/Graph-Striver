// https://leetcode.com/problems/01-matrix/

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BFS: Solution with queue.
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n);
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visited(m, vector<int> (n)), ans(m, vector<int> (n));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] == 0) q.push(vector<int>({i, j, 0})), visited[i][j] = 1;
            }
        }
        
        while(q.size()) {
            vector<int> par = q.front();
            q.pop();
            int r = par[0], c = par[1], d = par[2];
            
            // visited[r][c] = 1;
            ans[r][c] = d;

            if (r > 0 && mat[r-1][c] && !visited[r-1][c]) q.push(vector<int>({r-1, c, d+1})), visited[r-1][c] = 1;
            if (c > 0 && mat[r][c-1] && !visited[r][c-1]) q.push(vector<int>({r, c-1, d+1})), visited[r][c-1] = 1;
            if (r < m-1 && mat[r+1][c] && !visited[r+1][c]) q.push(vector<int>({r+1, c, d+1})), visited[r+1][c] = 1;
            if (c < n-1 && mat[r][c+1] && !visited[r][c+1]) q.push(vector<int>({r, c+1, d+1})), visited[r][c+1] = 1; 
        }

        return ans;
    }
};


class Solution {
    // Recursion: WA: Wrong Answer
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (ans[i][j] == -1){ans[i][j] = mat[i][j] == 0 ? 0 : solveDFS(mat, ans, m, n, i, j);}
            }
        }
        
        return ans;
    }

    int solveDFS(vector<vector<int>> &mat, vector<vector<int>> &ans, int &m, int &n, int i, int j){
        if (!mat[i][j]) return 0;

        if (ans[i][j] != -1) return ans[i][j];

        int left = 0, right = 0, up = 0, down = 0;

        if (i > 0 && !mat[i-1][j]) up = solveDFS(mat, ans, m, n, i-1, j);
        if (j > 0 && !mat[i][j-1]) left = solveDFS(mat, ans, m, n, i, j-1);
        if (i < m-1 && !mat[i+1][j]) down  = solveDFS(mat, ans, m, n, i+1, j);
        if (j < n-1 && !mat[i][j+1]) right = solveDFS(mat, ans, m, n, i, j+1);
        
        return ans[i][j] = 1 + min(min(up, left), min(down, right));
    }
};


class Solution {
    // BruteForce Intution: TLE: WA
    // [[0,0,0],[0,1,0],[1,1,1]] || Wrong Answer.
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), flag;
        vector<vector<int>> ans(m, vector<int> (n));

        for (int dis = 1; dis < m+n; ++dis)
        {
            flag = 1;

            // Record
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (mat[i][j]){
                        flag = 0;

                        // up 
                        if (i > 0 && !mat[i-1][j]) ans[i][j] = dis;
                        else if (j > 0 && !mat[i][j-1]) ans[i][j] = dis;
                        else if (i < m-1 && !mat[i+1][j]) ans[i][j] = dis;
                        else if (j < n-1 && !mat[i][j+1]) ans[i][j] = dis;
                        else continue;
                    }
                }
            }

            // Update
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (mat[i][j]){
                        // flag = 0;

                        // up 
                        if (i > 0 && !mat[i-1][j]) mat[i][j] = 0;
                        else if (j > 0 && !mat[i][j-1]) mat[i][j] = 0; 
                        else if (i < m-1 && !mat[i+1][j]) mat[i][j] = 0; 
                        else if (j < n-1 && !mat[i][j+1]) mat[i][j] = 0;
                        else continue;
                    }
                }
            }
            if (flag) break;
        }

        return ans;
    }
};

int main () {
    
    return 0;
}