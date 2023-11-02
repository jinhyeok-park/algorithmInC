#include <iostream>

int map[8][8] = {-1, };
int visit[8][8] = {-1, };
int cnt = 0;

int main(void)
{
    int N;
    std::cin >> N;
    for (int i = 0 ; i < N ; i ++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            int temp;
            std::cin >> temp;
            map[i][j] = temp;
        }
    }
    recur(0, 0, N);
}

int recur(int x, int y, int N)
{
    int pre = -1;
    for (int i = 0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            visit[i][j] = 1;
        }
    }
}