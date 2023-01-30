// https://leetcode.com/problems/is-graph-bipartite/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // BFS Solution: Using Queue
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        for (int i = 0; i < n; ++i)
        {
            if (color[i] == 0) {if(!fill(graph, color, i)) return false;}
        }
        return true;
    }

    bool fill(vector<vector<int>> &graph, vector<int> &color, int i){
        queue<pair<int, int>> q;
        q.push({i, 1});
        color[i] = 1;
        while(q.size()){
            pair<int, int> pr = q.front();
            q.pop();

            int node = pr.first, col = pr.second;
            
            for (int j = 0; j < graph[node].size(); ++j)
            {
                if (color[graph[node][j]]){
                    if (color[graph[node][j]] == col) return false;
                }
                else{
                    color[graph[node][j]] = -col;
                    q.push({graph[node][j], -col});
                }
            }
        }
        return true;
    }
};

class Solution {
    // DFS Solution
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