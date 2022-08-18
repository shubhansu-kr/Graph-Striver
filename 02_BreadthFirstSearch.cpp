// Breadth First Search 

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    void BFS(int stNode, vector<vector<int>> &list) {
        queue<int> q; 
        q.push(stNode);

        int n = list.size();
        vector<int> v(n, 0);
        v[stNode] = 1;

        while (q.size()) {
            cout << q.front() << " ";
            for (int i = 0; i < list[q.front()].size(); ++i)
            {
                if (!v[list[q.front()][i]]) {
                    q.push(list[q.front()][i]);
                    v[list[q.front()][i]] = 1;
                }
            }
            q.pop();
        }         
    }
};

int main () {
    vector<vector<int>> list = {
        {},
        {2, 6},
        {1, 3, 4}, 
        {2},
        {2, 5}, 
        {4, 8},
        {1, 7, 9},
        {6, 8},
        {5, 7},
        {6}
    };
    int stNode = 1;

    Solution Obj1; 
    Obj1.BFS(stNode, list);

    return 0;
}