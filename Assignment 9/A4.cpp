#include <iostream>
using namespace std;

int m, n;
int grid[100][100];
int visited[100][100];

int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, -1, 1};

void DFS(int x, int y)
{
    visited[x][y] = 1;

    for(int i = 0; i < 4; i++)
    {
        int nx = x + dirX[i];
        int ny = y + dirY[i];

        if(nx >= 0 && nx < m && ny >= 0 && ny < n)
        {
            if(grid[nx][ny] == 1 && visited[nx][ny] == 0)
                DFS(nx, ny);
        }
    }
}

int main()
{
    cin >> m >> n;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            visited[i][j] = 0;
        }
    }

    int islands = 0;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == 1 && visited[i][j] == 0)
            {
                islands++;
                DFS(i, j);
            }
        }
    }

    cout << islands << endl;

    return 0;
}
