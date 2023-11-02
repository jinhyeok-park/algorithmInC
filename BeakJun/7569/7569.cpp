#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int m, n , h;
int map[101][101][101] = {0};
int visited[101][101][101] = {0};

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
queue<tuple<int, int, int> > q;

void    bfs()
{
    while (!q.empty())
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for (int i = 0 ; i < 6 ; i ++)
        {
            int n_x = x + dx[i];
            int n_y = y + dy[i];
            int n_z = z + dz[i];
            if (n_x >= 0 && n_y >= 0 && n_z >= 0 && n_x < m && n_y < n && n_z < h)
            {
                if (map[n_z][n_y][n_x] == 0 && visited[n_z][n_y][n_x] == 0)
                {
                    q.push(make_tuple(n_x, n_y, n_z));
                    visited[n_z][n_y][n_x] = visited[z][y][x] + 1;
                }
            }
        }
    }
}

int main(void)
{
    cin >> m >> n >> h;
    for (int i = 0 ; i < h ; i ++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            for (int k = 0 ; k < m ; k++)
            {
                int temp;
                cin >> temp;
                map[i][j][k] = temp;
                if (temp == 1)
                    q.push(make_tuple(k,j,i));
            }
        }
    }
    bfs();
    int max = visited[0][0][0];
    for (int i = 0 ; i < h ; i ++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            for (int k = 0 ; k < m ; k++)
            {
                if (max < visited[i][j][k])
                    max = visited[i][j][k];
                if (visited[i][j][k] == 0 && map[i][j][k] == 0)
                {
                    cout << "-1";
                    return (0);
                }
            }
        }
    }
    cout << max;
}