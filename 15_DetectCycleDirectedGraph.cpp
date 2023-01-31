// https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Logic: If we detect a cycle we cannot complete all the course.
    // WA: 
    // 5
    // [[1,4],[2,4],[3,1],[3,2]]
public:
    vector<vector<int>> createAdjList(vector<vector<int>> &edges, int &n){
        vector<vector<int>> adj(n+1);
        for(auto &it: edges){
            // directed graph
            // adj[it[0]].emplace_back(it[1]);
            adj[it[1]].emplace_back(it[0]);
        }
        return adj;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = createAdjList(prerequisites, numCourses);
        
        vector<int> vis(numCourses);
        for (int i = 0; i < numCourses; ++i)
        {
            if(vis[i] == 0) {
                if (!dfs(numCourses, adj, vis, i)) return false;
            }
        }
        return true;
    }

    bool dfs(int &n, vector<vector<int>> &adj, vector<int> &vis, int &i){
        
        unordered_set<int> _set;
        stack<int> st;

        st.push(i);
        // _set.insert(i);
        vis[i] = 1;

        while(st.size()){
            int node = st.top();
            st.pop();

            if (_set.count(node)) return false;
            else _set.insert(node);

            for(auto &it: adj[node]){
                st.push(it);
                vis[it] = 1;
            }
        }

        return true;
    }
};

int main () {
    
    return 0;
}