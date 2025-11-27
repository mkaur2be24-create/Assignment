#include <iostream>
using namespace std;

#define INF 999999

int main()
{
    int N, E, K;
    cin >> N >> E >> K;

    int adj[100][100];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            adj[i][j] = 0;

    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1][v-1] = w;
    }

    int dist[100], visited[100];
    for(int i = 0; i < N; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[K-1] = 0;

    for(int c = 0; c < N - 1; c++)
    {
        int minDist = INF, u = -1;
        for(int i = 0; i < N; i++)
        {
            if(!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        visited[u] = 1;

        for(int v = 0; v < N; v++)
        {
            if(adj[u][v] != 0 && !visited[v] && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
        }
    }

    int result = 0;
    for(int i = 0; i < N; i++)
    {
        if(dist[i] == INF)
        {
            result = -1;
            break;
        }
        if(dist[i] > result)
            result = dist[i];
    }

    cout << result << endl;
    return 0;
}
