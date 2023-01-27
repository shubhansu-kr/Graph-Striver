// https://leetcode.com/problems/01-matrix/

#include <bits/stdc++.h>
using namespace std ;

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

// class Solution {
//     // BruteForce Intution: TLE: WA
//     // [[0,0,0],[0,1,0],[1,1,1]] || Wrong Answer.
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size(), flag;
//         vector<vector<int>> ans(m, vector<int> (n));

//         for (int dis = 1; dis < m+n; ++dis)
//         {
//             flag = 1;

//             // Record
//             for (int i = 0; i < m; ++i)
//             {
//                 for (int j = 0; j < n; ++j)
//                 {
//                     if (mat[i][j]){
//                         flag = 0;

//                         // up 
//                         if (i > 0 && !mat[i-1][j]) ans[i][j] = dis;
//                         else if (j > 0 && !mat[i][j-1]) ans[i][j] = dis;
//                         else if (i < m-1 && !mat[i+1][j]) ans[i][j] = dis;
//                         else if (j < n-1 && !mat[i][j+1]) ans[i][j] = dis;
//                         else continue;
//                     }
//                 }
//             }

//             // Update
//             for (int i = 0; i < m; ++i)
//             {
//                 for (int j = 0; j < n; ++j)
//                 {
//                     if (mat[i][j]){
//                         // flag = 0;

//                         // up 
//                         if (i > 0 && !mat[i-1][j]) mat[i][j] = 0;
//                         else if (j > 0 && !mat[i][j-1]) mat[i][j] = 0; 
//                         else if (i < m-1 && !mat[i+1][j]) mat[i][j] = 0; 
//                         else if (j < n-1 && !mat[i][j+1]) mat[i][j] = 0;
//                         else continue;
//                     }
//                 }
//             }
//             if (flag) break;
//         }

//         return ans;
//     }
// };

int main () {
    
    return 0;
}