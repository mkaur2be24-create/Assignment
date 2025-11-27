#include <iostream>
using namespace std;

class Graph
{
public:
    int V;
    int **adj;

    Graph(int n)
    {
        V = n;
        adj = new int*[V];
        for(int i = 0; i < V; i++)
        {
            adj[i] = new int[V];
            for(int j = 0; j < V; j++)
                adj[i][j] = 0;
        }
    }

    void addEdge(int u, int v)
    {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void DFSUtil(int node, int visited[])
    {
        visited[node] = 1;
        for(int i = 0; i < V; i++)
        {
            if(adj[node][i] == 1 && visited[i] == 0)
                DFSUtil(i, visited);
        }
    }

    int connectedComponents()
    {
        int *visited = new int[V];
        for(int i = 0; i < V; i++)
            visited[i] = 0;

        int count = 0;
        for(int i = 0; i < V; i++)
        {
            if(visited[i] == 0)
            {
                DFSUtil(i, visited);
                count++;
            }
        }

        delete[] visited;
        return count;
    }
};
