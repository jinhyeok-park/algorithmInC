#include <iostream>

int main(void)
{
    int N;
    int temp;
    int origin;
    int total;
    std::cin >> N;
    temp = N;
    origin = N;
    total = 0;
    for (int i = 0 ; i < N ; i ++)
    {
        total += i;
        temp = i;
        while (temp)
        {
            total += temp % 10;
            temp /= 10;
        }
        if (total == N)
        {
            std::cout << i << std::endl;
            return (0);
        }
        total = 0;
    }
    std::cout << "0" << std::endl;
    return (0);
}