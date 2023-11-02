#include <iostream>

int map[501][501] = {-1, };

int main(void)
{
    int N, M, B;
    std::cin >> N >> M >> B;
    for (int i = 0 ; i < N ; i ++)
    {
        for (int j = 0 ; j < M ; j ++)
        {
            int temp;
            std::cin >> temp;
            map[i][j] = temp;
        }
    }
}