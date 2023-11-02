#include <iostream>

long long N;
int j = 0;

int recur(long long N)
{
    if ( N == 0)
        return (0);
    // else if (N == 1)
    //     return (1);
    if (N % 2)
        return (1 - recur(N/ 2));
    return (recur(N / 2));
}

int main(void)
{
    std::cin >> N;
    int i = recur(N - 1);
    std::cout << i << std::endl;
}
