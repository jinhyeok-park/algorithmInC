#include <iostream>
#include <queue>

using namespace std;

int visited[100001] = {0};
queue<int> q;
int N, K;
int di[3] = {-1, 1, 0};

int main(void)
{
    cin >> N >> K;

    q.push(N);
    while (!q.empty())
    {
        int cur_p = q.front();
        q.pop();
        if (cur_p == K)
            break;
        for (int i = 0 ; i < 3 ; i++)
        {
            int n_p; 
            if (!di[i]) 
                n_p = cur_p * 2;
            else
                n_p = cur_p + di[i];
            if (n_p >= 0 && n_p < 100001 && visited[n_p] == 0)
            {
                q.push(n_p);
                visited[n_p] = visited[cur_p] + 1;
            }
        }
    }
    cout << visited[K];
}