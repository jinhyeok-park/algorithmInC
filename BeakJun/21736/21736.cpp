#include <iostream>
#include <queue>

using namespace std;

int N, M;
char    map[601][601] = {'0'};
int visited[601][601] = {0};
int count = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void    bfs(void)
{
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        if (map[cur_y][cur_x] == 'P')
            count++;
        for (int i = 0 ; i < 4 ; i++)
        {
            int n_x = cur_x + dx[i];
            int n_y = cur_y + dy[i];
            if (n_x >= 0 && n_y >= 0 && n_x < M && n_y < N)
            {
                if (map[n_y][n_x] != 'X' && visited[n_y][n_x] != 1)
                {
                    q.push(make_pair(n_x,n_y));
                    visited[n_y][n_x] = 1;
                }
            }
        }
    }
}

int main(void)
{
    int start_x;
    int start_y;

    cin >> N >> M;
    for (int i = 0 ; i < N ; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0 ; j < M ; j++)
        {
            map[i][j] = temp[j];
            if (map[i][j] == 'I')
            {
                q.push(make_pair(j,i));
                visited[i][j] = 1;
            }
        }
    }
    bfs();
    if (!count)
    {
        cout << "TT";
        return (0);
    }
    cout << count;
}
