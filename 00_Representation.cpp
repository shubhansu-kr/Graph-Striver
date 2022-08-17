// Graph Representation:

// Given n nodes and m edges, directed/undirected graph

// There are two ways to represent a graph:
// 1. Using Adjacency Matrix     2. Using list/vector

#include <bits/stdc++.h>
using namespace std;

class Solution6
{
    // Using vector
    // Space Used : 2*N ; N -> Number of nodes 
    // Directed Graph || Weighted Graph
public:
    vector<vector<pair<int, int>>> list() {
        int m, n;
        cout << "Enter number of nodes: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> m;

        vector<vector<pair<int, int>>> list(n+1);
        for (int i = 0; i < m; ++i)
        {
            int u, v, weight;
            cout << "Enter u: ";
            cin >> u;
            cout << "Enter v: ";
            cin >> v;
            cout << "Enter Weight: ";
            cin >> weight;

            // Link u->v only
            list[u].push_back({v, weight});
        }

        return list;
    }
};

class Solution5
{
    // Using vector
    // Space Used : 3*N ; N -> Number of nodes 
    // Undirected Graph || Weighted Graph 
public:
    vector<vector<pair<int, int>>> list() {
        int m, n;
        cout << "Enter number of nodes: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> m;

        vector<vector<pair<int, int>>> list(n+1);
        for (int i = 0; i < m; ++i)
        {
            int u, v, weight;
            cout << "Enter u: ";
            cin >> u;
            cout << "Enter v: ";
            cin >> v;
            cout << "Enter weight: ";
            cin >> weight;

            list[u].push_back({v, weight});
            list[v].push_back({u, weight});
        }

        return list;
    }
};

class Solution4
{
    // User input based: Adjacency Matrix 
    // Space used: N^2 

    // Undirected Graph || Weighted graph 
public:
    vector<vector<int>> adjacencyMatrix()
    {
        int m, n;
        cout << "Enter number of nodes: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> m;

        vector<vector<int>> am(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
        {
            int u, v, weight;
            cout << "Enter u: ";
            cin >> u;
            cout << "Enter v: ";
            cin >> v;

            am[u][v] = weight;
            // Instead of storing 1 for i j , weight is stored 
        }

        return am;
    }
};

class Solution3
{
    // Using vector
    // Space Used : N ; N -> Number of nodes 
    // Directed Graph
public:
    vector<vector<int>> list() {
        int m, n;
        cout << "Enter number of nodes: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> m;

        vector<vector<int>> list(n+1);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cout << "Enter u: ";
            cin >> u;
            cout << "Enter v: ";
            cin >> v;

            // Link u->v only
            list[u].emplace_back(v);
        }

        return list;
    }
};

class Solution2
{
    // Using vector
    // Space Used : 2*N ; N -> Number of nodes 
    // Undirected Graph
public:
    vector<vector<int>> list() {
        int m, n;
        cout << "Enter number of nodes: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> m;

        vector<vector<int>> list(n+1);
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cout << "Enter u: ";
            cin >> u;
            cout << "Enter v: ";
            cin >> v;

            list[u].emplace_back(v);
            list[v].emplace_back(u);
        }

        return list;
    }
};

class Solution1
{
    // User input based: Adjacency Matrix 
    // Space used: N^2 
    // Undirected Graph
public:
    vector<vector<int>> adjacencyMatrix()
    {
        int m, n;
        cout << "Enter number of nodes: ";
        cin >> n;
        cout << "Enter number of edges: ";
        cin >> m;

        vector<vector<int>> am(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cout << "Enter u: ";
            cin >> u;
            cout << "Enter v: ";
            cin >> v;

            am[u][v] = 1;
        }

        return am;
    }
};

class Solution
{
    // Input based
    // Space Used: N^2
    // Undirected Graph
public:
    vector<vector<int>> adjacencyMatrix(vector<vector<int>> edges, int n)
    {
        // n: Number of nodes
        vector<vector<int>> am(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < edges.size(); ++i)
        {
            am[edges[i][0]][edges[i][1]] = 1;
        }
        // 1: represents an edge between ith and jth node, 0: represents no edge

        return am;
    }
};

int main()
{

    return 0;
}