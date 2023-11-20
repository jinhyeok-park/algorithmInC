#include <iostream>
#include <vector>
#include <utility>

std::vector<int> g[1000001];
int visited[1000001] = {0,};
int parent[1000001] = {0, };
int N;
void    dfs(int node)
{
    visited[node] = 1;
    for (int i = 0 ; i < g[node].size(); i ++)
    {
        int next = g[node][i];
        if (!visited[next])
        {
            parent[next] = node;
            dfs(next);
        }
    }
}

int main(void)
{
    std::cin >> N;
    for (int i = 0 ; i < N - 1; i++)
    {
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    for (int i = 2 ; i < parent[i] ; i++ )
    {
        // if (parent[i] == 0)
        //     return (0);
        std::cout << parent[i] << std::endl;
    }
}