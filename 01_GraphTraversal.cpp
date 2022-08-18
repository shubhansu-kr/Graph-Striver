// Graph Traversal

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void traversal(int N, vector<vector<int>> list)
    {
        // N is the number of nodes and list is the edges

        // Visited Graph Concept
        vector<int> v(N + 1, 0);
        for (int j = 1; j <= N; ++j)
        {
            for (int i = 0; i < list[j].size(); ++i)
            {
                if (!v[list[j][i]])
                {
                    cout << list[j][i] << " ";
                    v[list[j][i]] = 1;
                }
            }
        }
        cout << endl;
    }
};

int main()
{
    vector<vector<int>> list = {{}, {2, 3}, {3, 5, 6}, {4, 5}, {1}, {1, 2}, {2, 4}};
    int N = 6;

    Solution Obj1;
    Obj1.traversal(N, list);

    return 0;
}