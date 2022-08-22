// Depth First Search

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> DFS(vector<vector<int>> &list, int stNode)
    {
        vector<int> visited(list.size(), 0), traversal;
        solveDFS(visited, traversal, list, stNode);
        return traversal;
    }
    void solveDFS(vector<int> &visited, vector<int> &traversal, vector<vector<int>> &list, int node)
    {

        traversal.emplace_back(node);
        visited[node] = 1;

        for (int i = 0; i < list[node].size(); ++i)
        {
            if (visited[list[node][i]])
                continue;
            else
                solveDFS(visited, traversal, list, list[node][i]);
        }
    }
};

int main()
{
    vector<vector<int>> list = {
        {},
        {2, 3},
        {1, 5, 6},
        {1, 4, 7},
        {3, 8},
        {2},
        {2},
        {3, 8},
        {7, 4, 9},
        {8}};

    Solution Obj1;
    vector<int> traversal = Obj1.DFS(list, 1);
    for (auto &it : traversal)
        cout << it << " ";
    cout << endl;
    
    return 0;
}