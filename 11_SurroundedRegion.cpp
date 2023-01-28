// https://leetcode.com/problems/surrounded-regions/

// Given an m x n matrix board containing 'X' and 'O', capture all regions 
// that are 4-directionally surrounded by 'X'.
// A region is captured by flipping all 'O's into 'X's in that surrounded region.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // DFS: Traverse the boundry O's and flood all the connected zeroes.
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n));

        vector<vector<char>> ans(m, vector<char>(n, 'X'));
        stack<pair<int, int>> st;

        for (int j = 0; j < n; ++j)
        {
            if (board[0][j] == 'O') {
                visited[0][j] = 1;
                st.push({0, j});
            } 
            if (board.size() > 1) {
                if (board[m-1][j] == 'O'){
                    visited[m-1][j] = 1;
                    st.push({m-1, j});
                }
            }
        }

        for (int i = 1; i < m-1; ++i)
        {
            if (board[i][0] == 'O') {
                visited[i][0] = 1;
                st.push({i, 0});
            } 
            if (board.size() > 1) {
                if (board[i][n-1] == 'O'){
                    visited[i][n-1] = 1;
                    st.push({i, n-1});
                }
            }
        }
        
        while(st.size()){
            pair<int, int> p = st.top();
            st.pop();

            int r = p.first, c = p.second, nRow, nCol;
            ans[r][c] = 'O';

            vector<int> rowShift = {-1, 0, +1, 0}, colShift = {0, -1, 0, +1};

            for (int i = 0; i < 4; ++i)
            {
                nRow = r + rowShift[i];
                nCol = c + colShift[i];

                if (nRow >= 0 && nCol >= 0 && nRow < m && nCol < n){
                    if (board[nRow][nCol] == 'O' && !visited[nRow][nCol]){
                        st.push({nRow, nCol});
                        visited[nRow][nCol] = 1;
                    }
                }
            }             
        }

        board = ans;
        // return ans;
    }
};

int main () {


    return 0;
}