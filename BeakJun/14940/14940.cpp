#include <iostream>
#include <queue>

using namespace std;

int r, c;
int map[1001][1001] = {0};
int visited[1001][1001] = {0};
int dx[4] = {1, -1 , 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<pair<int, int> > q;

int main(void)
{
    cin >> r >> c;
    for (int i = 0 ; i < r ; i++)
    {
        for (int j = 0; j < c ; j++)
        {
            int temp;
            cin >> temp;
            map[i][j] = temp;
            if (map[i][j] == 2)
            {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
        }
    }
    while (!q.empty())
    {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        for (int i = 0 ; i < 4 ; i++)
        {
            int n_y = cur_y + dy[i];
            int n_x = cur_x + dx[i];
            if (n_y >= 0 && n_x >= 0 && n_y < r && n_x < c)
            {
                if (map[n_y][n_x] != 0 && visited[n_y][n_x] == 0)
                {
                    visited[n_y][n_x] = visited[cur_y][cur_x] + 1;
                    q.push(make_pair(n_y, n_x));
                }
            }
        }
    }
    for (int i = 0 ; i < r ; i++)
    {
        for (int j = 0 ; j < c; j++)
        {
            if (map[i][j] == 1 && visited[i][j] == 0)
                cout << "-1" << " ";
            else
                cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}
