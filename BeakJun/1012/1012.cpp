#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int map[51][51];
bool visit[51][51];
int cnt;
int M, N, K;
int dx[4] = {1 , -1, 0, 0};
int dy[4] = {0 , 0, 1, -1};
queue<pair<int ,int> > bfs_que;

void    init(void)
{
    memset(map, 0, sizeof(map));
    memset(visit, false, sizeof(visit));
    cnt = 0;
}

void    bfs(int x, int y)
{
    bfs_que.push(make_pair(x, y));
    while (!bfs_que.empty())
    {
        int cur_x = bfs_que.front().first;
        int cur_y = bfs_que.front().second;
        bfs_que.pop();
        for (int i = 0 ; i < 4 ; i++)
        {
            int n_x = cur_x + dx[i];
            int n_y = cur_y + dy[i];
            if (n_x >= 0 && n_x < M && n_y >= 0 && n_y < N)
            {
                if (map[n_x][n_y] == 1 && visit[n_x][n_y] == 0)
                {
                    bfs_que.push(make_pair(n_x, n_y));
                    visit[n_x][n_y] = true;
                }
            }
        }
    }
}

int main(void)
{
    vector<int> result;
    int T;
    cin >> T;
    for (int i = 0 ; i < T ; i++)
    {
        init();
        cin >> M >> N >> K;
        queue<pair<int, int> > que;
        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            que.push(make_pair(x, y));
            map[x][y] = 1;
        }
        while (!que.empty())
        {
            int n_x = que.front().first;
            int n_y = que.front().second;
            que.pop();
            if (!visit[n_x][n_y])
            {
                cnt++;
                bfs(n_x, n_y);
            }
        }
        result.push_back(cnt);
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return (0);
}

