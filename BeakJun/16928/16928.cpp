#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[101] = {0};
int visited[101] = {0};
int dice[6] = {1,2,3,4,5,6};
queue<int> q;

void    bfs(void)
{
    q.push(1);
    while (!q.empty())
    {
        int cur_point = q.front();
        q.pop();
        if (cur_point == 100)
            break;
        for(int i = 0 ; i < 6 ; i++)
        {
            int n_point = cur_point + dice[i];
            if (n_point > 1 && n_point <= 100)
            {
                while (map[n_point] != 0)
                    n_point = map[n_point];
                if (!visited[n_point])
                {
                    q.push(n_point);
                    visited[n_point] = visited[cur_point] + 1;
                }
            }
        }
    }
}

int main(void)
{
    cin >> N >> M ;
    for (int i = 0 ; i < N + M ; i ++)
    {
        int from;
        int to;
        cin >> from >> to;
        map[from] = to;
    }
    bfs();
    // for (int i = 0 ; i < 101 ; i++)
    // {
    //     cout << visited[i] << " ";
    // }
    cout << visited[100];
}
