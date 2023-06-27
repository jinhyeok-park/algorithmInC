#include <iostream>
#include <queue>

using namespace std;

int N,M;
int map[101][101] = {0};
int visited[101][101] = {0};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int count = 0;

queue<pair<int, int>> q;

void    bfs(int x, int y)
{
    q.push(make_pair(x, y));
    visited[y][x] = 1;
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int n_x = cur_x + dx[i];
            int n_y = cur_y + dy[i];
            if (n_y >= 0 && n_x >= 0 && n_x < M && n_y < N)
            {
                if (map[n_y][n_x] == 1 && visited[n_y][n_x] == 0)
                {
                    visited[n_y][n_x] = visited[cur_y][cur_x] + 1;
                    q.push(make_pair(n_x, n_y));
                }
            }
        }
    }
}

int main(void)
{
    cin >> N >> M;
    for (int i = 0 ; i < N ; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0 ; j < M ; j++)
        {
            map[i][j] = temp[j] - '0';
        }
    }
    bfs(0, 0);
    cout << visited[N - 1][M - 1];
}
