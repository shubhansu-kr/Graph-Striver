// https://leetcode.com/problems/rotting-oranges/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // intution 
public:
    int r[4] = {0, -1, 0, +1};
    int c[4] = {-1, 0, +1, 0};
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n, 0));

        int flag = 0, ans = 0, slack = 0;
        do {
            flag = 0, slack = 0;
            vector<vector<int>> prev(m, vector<int> (n, 0));
            for (int i = 0; i < m; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    if(grid[i][j] == 2 && !visited[i][j] && !prev[i][j]) {
                        solve(grid, prev, slack, i, j);
                        visited[i][j] = 1;
                        flag = 1;
                    }
                }
                
            }
            if (slack) ++ans;
        }while(flag);
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }

    void solve(vector<vector<int>> &grid, vector<vector<int>> &prev, int &slack, int i, int j) {
        grid[i][j] = 0;
        int row, col;
        for (int k = 0; k < 4; ++k)
        {
            row = i + r[k];
            col = j + c[k];

            if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) continue;

            if (grid[row][col] == 1) grid[row][col] = 2, prev[row][col] = 1, slack = 1;
        }
        return ;
    }

    // void longestSubSeq(string &s, int &k)
    // {
    //     string sk;
    //     while (k--)
    //     {
    //         sk += s;
    //     }

    //     int count = 0, ans = INT_MIN, flag = 0;
    //     for (int i = 0; i < sk.length(); ++i)
    //     {
    //         if (sk[i] == '0')
    //         {
    //             ++count;
    //         }
    //         else
    //         {
    //             count = 0;
    //             ans = max(count, ans);
    //         }
    //     }
    //     string res(ans, '0');
    //     cout << res << endl;
    // }
};

// bool isUnique(string s) {
//     char x = s[0];
//     for (int i = 1; i < s.length(); ++i)
//     {
//         if (s[i] != x) return false;
//     }
//     return true;
// }

int main()
{

    // int k;
    // string s;

    // cin >> k >> s;

    // string sk;
    // while (k--)
    // {
    //     sk += s;
    // }

    // int count = 0, ans = INT_MIN, flag = 0;
    // for (int i = 0; i < sk.length(); ++i)
    // {
    //     if (sk[i] == '0')
    //     {
    //         ++count;
    //     }
    //     else
    //     {
    //         count = 0;
    //         ans = max(count, ans);
    //     }
    // }

    // cout << ans << endl;

    // int N, x; 
    // cin >> N;

    // int minT = INT_MAX;
    // for (int i = 0; i < N; ++i)
    // {
    //     cin >> x ;
    //     minT = min(minT, x);
    // }
    // cout << minT << endl;


    

    // int N, K;
    // int temp = K;
    // string s = to_string(N);
    // string b;
    // while(temp--) {
    //     b += s;
    // }
       
    // while(!isUnique(b)) {
    //     int sum = 0;
    //     for (int i = 0; i < b.length(); ++i)
    //     {
    //         sum += s[i]-'0';
    //     }
    //     b = to_string(sum);
    // }
    // cout << b[0] << endl;

    return 0;
}