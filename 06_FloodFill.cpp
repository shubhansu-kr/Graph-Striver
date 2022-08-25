// https://leetcode.com/problems/flood-fill/

// An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.

// You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.

// Return the modified image after performing the flood fill.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Optimise 
public:
    vector<int> dRow = {-1, 0, 1, 0}, dCol = {0, 1, 0, -1};
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int k = image[sr][sc]; 
        if (k == color) return image;
        DFS(image, color, k, sr, sc);
        return image;
    }

    void DFS(vector<vector<int>> &image, int &color, int &k, int i, int j)
    {
        image[i][j] = color;

        for (int z = 0; z < 4; ++z)
        {
            int m = i + dRow[z], n = j + dCol[z];
            if (m < 0 || m >= image.size() || n < 0 || n >= image[0].size())
                continue;
            if (image[m][n] == k)
            {
                DFS(image, color, k, m, n);
            }
        }
        return;
    }
};

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int k = image[sr][sc]; 
        if (k == color) return image;
        DFS(image, color, k, sr, sc);
        return image;
    }

    void DFS(vector<vector<int>> &image, int &color, int &k, int i, int j)
    {
        image[i][j] = color;

        for (int row = -1; row < 2; ++row)
        {
            for (int col = -1; col < 2; ++col)
            {
                if (col == row || col + row == 0)
                    continue;

                int m = i + row, n = j + col;
                if (m < 0 || m >= image.size() || n < 0 || n >= image[0].size())
                    continue;
                if (image[m][n] == k)
                {
                    DFS(image, color, k, m, n);
                }
            }
        }
        return;
    }
};

int main()
{
    vector<vector<int>> image = {{1,1,1}, {1,1,0}, {1,0,1}};
    int color  = 2;
    return 0;
}