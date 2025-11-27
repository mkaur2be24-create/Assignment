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

    void addEdge(int u, int v, int w)
    {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    void BFS(int start)
    {
        int *visited = new int[V];
        for(int i = 0; i < V; i++)
            visited[i] = 0;

        int queue[100], front = 0, rear = 0;
        queue[rear++] = start;
        visited[start] = 1;

        cout << "BFS: ";
        while(front < rear)
        {
            int node = queue[front++];
            cout << node << " ";
            for(int i = 0; i < V; i++)
            {
                if(adj[node][i] != 0 && visited[i] == 0)
                {
                    visited[i] = 1;
                    queue[rear++] = i;
                }
            }
        }
        cout << endl;
        delete[] visited;
    }

    void DFSUtil(int node, int visited[])
    {
        visited[node] = 1;
        cout << node << " ";
        for(int i = 0; i < V; i++)
        {
            if(adj[node][i] != 0 && visited[i] == 0)
                DFSUtil(i, visited);
        }
    }

    void DFS(int start)
    {
        int *visited = new int[V];
        for(int i = 0; i < V; i++)
            visited[i] = 0;

        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
        delete[] visited;
    }

    int findMinKey(int key[], int mstSet[])
    {
        int min = 999999, index = -1;
        for(int i = 0; i < V; i++)
        {
            if(mstSet[i] == 0 && key[i] < min)
            {
                min = key[i];
                index = i;
            }
        }
        return index;
    }

    void Prim(int start)
    {
        int *parent = new int[V];
        int *key = new int[V];
        int *mstSet = new int[V];

        for(int i = 0; i < V; i++)
        {
            key[i] = 999999;
            mstSet[i] = 0;
        }

        key[start] = 0;
        parent[start] = -1;

        cout << "Prim MST edges: ";
        for(int i = 0; i < V - 1; i++)
        {
            int u = findMinKey(key, mstSet);
            mstSet[u] = 1;

            for(int v = 0; v < V; v++)
            {
                if(adj[u][v] != 0 && mstSet[v] == 0 && adj[u][v] < key[v])
                {
                    parent[v] = u;
                    key[v] = adj[u][v];
                }
            }
        }

        for(int i = 0; i < V; i++)
        {
            if(parent[i] != -1)
                cout << parent[i] << "-" << i << " ";
        }
        cout << endl;

        delete[] parent;
        delete[] key;
        delete[] mstSet;
    }

    int findSetParent(int parent[], int i)
    {
        while(parent[i] != i)
            i = parent[i];
        return i;
    }

    void Union(int parent[], int x, int y)
    {
        int px = findSetParent(parent, x);
        int py = findSetParent(parent, y);
        parent[px] = py;
    }

    void Kruskal()
    {
        int parent[100];
        for(int i = 0; i < V; i++)
            parent[i] = i;

        cout << "Kruskal MST edges: ";
        int edges = 0;
        while(edges < V - 1)
        {
            int min = 999999, u = -1, v = -1;
            for(int i = 0; i < V; i++)
            {
                for(int j = 0; j < V; j++)
                {
                    if(adj[i][j] != 0)
                    {
                        int pi = findSetParent(parent, i);
                        int pj = findSetParent(parent, j);
                        if(pi != pj && adj[i][j] < min)
                        {
                            min = adj[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }

            if(u != -1 && v != -1)
            {
                Union(parent, u, v);
                cout << u << "-" << v << " ";
                edges++;
            }
        }
        cout << endl;
    }

    void Dijkstra(int start)
    {
        int dist[100], visited[100];
        for(int i = 0; i < V; i++)
        {
            dist[i] = 999999;
            visited[i] = 0;
        }

        dist[start] = 0;

        cout << "Dijkstra from " << start << ": ";
        for(int c = 0; c < V - 1; c++)
        {
            int min = 999999, u = -1;
            for(int i = 0; i < V; i++)
            {
                if(!visited[i] && dist[i] < min)
                {
                    min = dist[i];
                    u = i;
                }
            }

            visited[u] = 1;

            for(int v = 0; v < V; v++)
            {
                if(adj[u][v] != 0 && visited[v] == 0 && dist[u] + adj[u][v] < dist[v])
                    dist[v] = dist[u] + adj[u][v];
            }
        }

        for(int i = 0; i < V; i++)
            cout << dist[i] << " ";
        cout << endl;
    }
};