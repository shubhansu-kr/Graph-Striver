// https://leetcode.com/problems/course-schedule/description/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // DFS : Use Path vector to track the visited path node instead of set. 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses+1);
        for(auto &it: prerequisites){
            adj[it[1]].emplace_back(it[0]);
        }

        vector<int> vis(numCourses), path(numCourses);
        for (int i = 0; i < numCourses; ++i)
        {
            if (!vis[i] && dfs(numCourses, adj, vis, path, i)) return false;
        }
        
        return true;
    }

    bool dfs(int &n, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path, int &i){
        if (path[i]) return true;
        if (vis[i]) return false;

        vis[i] = 1;
        path[i] = 1;

        for(int &it: adj[i]) {
            if (dfs(n, adj, vis, path, it)) return true;   
        }
        path[i] = 0;

        return false;
    }
};

class Solution {
    // TLE
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses+1);
        for(auto &it: prerequisites){
            adj[it[1]].emplace_back(it[0]);
        }

        unordered_set<int> _set;
        vector<int> vis(numCourses);
        for (int i = 0; i < numCourses; ++i)
        {
            if (!vis[i] && !dfs(numCourses, adj, vis, _set, i)) return false;
        }
        return true;
    }

    bool dfs(int &n, vector<vector<int>> &adj, vector<int> &vis, unordered_set<int> &_set, int &i){
        if(vis[i]) return true;

        if (_set.count(i)) return false;
        else _set.insert(i);

        for(auto &it: adj[i]){
            if(!dfs(n, adj, vis, _set, it)) return false;
        }

        _set.erase(i); 
        return true;
    }
};

class Solution {
    // TLE 

    // 100 
    // [[1,0],[2,0],[2,1],[3,1],[3,2],[4,2],[4,3],[5,3],[5,4],[6,4],[6,5],[7,5],[7,6],[8,6],[8,7],[9,7],[9,8],[10,8],
    // [10,9],[11,9],[11,10],[12,10],[12,11],[13,11],[13,12],[14,12],[14,13],[15,13],[15,14],[16,14],[16,15],[17,15],
    // [17,16],[18,16],[18,17],[19,17],[19,18],[20,18],[20,19],[21,19],[21,20],[22,20],[22,21],[23,21],[23,22],[24,22],
    // [24,23],[25,23],[25,24],[26,24],[26,25],[27,25],[27,26],[28,26],[28,27],[29,27],[29,28],[30,28],[30,29],[31,29],[31,
    // 30],[32,30],[32,31],[33,31],[33,32],[34,32],[34,33],[35,33],[35,34],[36,34],[36,35],[37,35],[37,36],[38,36],[38,37],
    // [39,37],[39,38],[40,38],[40,39],[41,39],[41,40],[42,40],[42,41],[43,41],[43,42],[44,42],[44,43],[45,43],[45,44],[46,
    // 44],[46,45],[47,45],[47,46],[48,46],[48,47],[49,47],[49,48],[50,48],[50,49],[51,49],[51,50],[52,50],[52,51],[53,51],
    // [53,52],[54,52],[54,53],[55,53],[55,54],[56,54],[56,55],[57,55],[57,56],[58,56],[58,57],[59,57],[59,58],[60,58],[60,
    // 59],[61,59],[61,60],[62,60],[62,61],[63,61],[63,62],[64,62],[64,63],[65,63],[65,64],[66,64],[66,65],[67,65],[67,66],
    // [68,66],[68,67],[69,67],[69,68],[70,68],[70,69],[71,69],[71,70],[72,70],[72,71],[73,71],[73,72],[74,72],[74,73],[75,
    // 73],[75,74],[76,74],[76,75],[77,75],[77,76],[78,76],[78,77],[79,77],[79,78],[80,78],[80,79],[81,79],[81,80],[82,80],
    // [82,81],[83,81],[83,82],[84,82],[84,83],[85,83],[85,84],[86,84],[86,85],[87,85],[87,86],[88,86],[88,87],[89,87],[89,
    // 88],[90,88],[90,89],[91,89],[91,90],[92,90],[92,91],[93,91],[93,92],[94,92],[94,93],[95,93],[95,94],[96,94],[96,95],
    // [97,95],[97,96],[98,96],[98,97],[99,97]]
    
public:
    vector<vector<int>> createAdjList(vector<vector<int>> &edges, int &n){
        vector<vector<int>> adj(n+1);
        for(auto &it: edges){
            adj[it[1]].emplace_back(it[0]);
        }
        return adj;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj = createAdjList(prerequisites, numCourses);
        unordered_set<int> _set;
        vector<int> vis(numCourses);
        for (int i = 0; i < numCourses; ++i)
        {
            if (!dfs(numCourses, adj, vis, _set, i)) return false;
        }
        return true;
    }

    bool dfs(int &n, vector<vector<int>> &adj, vector<int> &vis, unordered_set<int> &_set, int &i){
        if(vis[i]) return true;

        if (_set.count(i)) return false;
        else _set.insert(i);

        for(auto &it: adj[i]){
            if(!dfs(n, adj, vis, _set, it)) return false;
        }

        _set.erase(i); 
        return true;
    }
};

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