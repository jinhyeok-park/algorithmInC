#include <iostream>

int N, M;
int temp;

int main(void)
{
    std::cin >> N >> M;
    for (int i = 0 ; i < N - M ; i ++)
    {
        std::cout << i << " " << i + 1 << std::endl;
        temp = i + 1;
    }
    for (int i = 1; i < M ; i ++)
    {
        std::cout << temp << " " << temp + i << std::endl;
    }
}