// https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);

        for (int i = 0; i < n; ++i)
        {
            if (color[i] == 0) {
                if(!fill(graph, color, i)) return false;
            }
        }
        
        return true;
    }

    bool fill(vector<vector<int>> &graph, vector<int> &color, int i, int col = 1){
        if (color[i]){return color[i] == col;}

        color[i] = col;
        for (int j = 0; j < graph[i].size(); ++j)
        {
            if (!fill(graph, color, graph[i][j], -col)) return false;
        }
        
        return true;
    }
};

int main () {
    
    return 0;
}