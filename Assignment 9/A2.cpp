#include <iostream>
using namespace std;

#define INF 999999

int main()
{
    int m, n;
    cin >> m >> n;

    int grid[100][100];
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int total = m * n;

    int dist[10000], visited[10000];
    for(int i = 0; i < total; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[0] = grid[0][0];

    int dirX[4] = {-1, 1, 0, 0};
    int dirY[4] = {0, 0, -1, 1};

    for(int c = 0; c < total; c++)
    {
        int minDist = INF, u = -1;

        for(int i = 0; i < total; i++)
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

        int ux = u / n;
        int uy = u % n;

        for(int k = 0; k < 4; k++)
        {
            int vx = ux + dirX[k];
            int vy = uy + dirY[k];

            if(vx >= 0 && vx < m && vy >= 0 && vy < n)
            {
                int v = vx * n + vy;
                int w = grid[vx][vy];

                if(!visited[v] && dist[u] + w < dist[v])
                    dist[v] = dist[u] + w;
            }
        }
    }

    cout << dist[total - 1] << endl;

    return 0;
}
