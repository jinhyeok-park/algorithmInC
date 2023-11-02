#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
vector<pair<int ,int > > map;
int computer, connected_count;
vector<int> visited(101, 0);
queue<int> q;

int cnt = 0;

void    bfs(void)
{
    visited[1] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int i = 0 ; i < map.size() ; i++)
        {
            if (map[i].first == x && visited[map[i].second] == 0)
            {
                q.push(map[i].second);
                visited[map[i].second] = 1;
            }
            else if (map[i].second == x && visited[map[i].first] == 0)
            {
                q.push(map[i].first);
                visited[map[i].first] = 1;
            }
        }
    }
}

int main(void)
{
    cin >> computer >> connected_count;

    for (int i = 0 ; i < connected_count ; i++)
    {
        int x;
        int y;
        cin >> x >> y;
        map.push_back(make_pair(x, y));
    }
    q.push(1);
    bfs();
    int ret = count(visited.begin() + 2 , visited.end(), true);
    cout << ret;

}