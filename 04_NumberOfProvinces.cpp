// https://leetcode.com/problems/number-of-provinces/

// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // DFS Solution 
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> visited(isConnected.size(), 0);
        int prov = 0;
        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (!visited[i])
            {
                ++prov;
                DFS(isConnected, visited, i);
            }
        }
        return prov;
    }
    void DFS(vector<vector<int>> &list, vector<int> &visited, int node)
    {
        visited[node] = 1;
        for (int i = 0; i < list.size(); ++i)
        {
            if (!list[node][i] || visited[i]) continue;
            else DFS(list, visited, i);
        }
    }
};

class Solution
{
    // BFS Solution 
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        vector<int> visited(isConnected.size(), 0);
        int prov = 0;
        for (int i = 0; i < isConnected.size(); ++i)
        {
            if (!visited[i])
            {
                ++prov;
                BFS(isConnected, visited, i);
            }
        }
        return prov;
    }
    void BFS(vector<vector<int>> &list, vector<int> &visited, int node)
    {
        queue<int> order;
        order.push(node);
        visited[node] = 1;
        while (order.size())
        {
            node = order.front();
            for (int i = 0; i < list.size(); ++i)
            {
                if (!list[node][i] || visited[i]) continue;
                else
                    order.push(i), visited[i] = 1;
            }
            order.pop();
        }
    }
};

int main()
{

    return 0;
}