#include <iostream>


long long    divide(long long A, long long B, long long C); // power - 10 cur_val = 10 ^ 10

int main(void)
{

    long long A, B, C;
    std::cin >> A >> B >> C;
    // 10 ^ 10 % 12 = 4;
    //10000000000 % 12 = 4;
    //((100000 mod 12 ) * (100000 mod 12))mod 12 = 1000000000 mod 12;
    //(10000 mod 12) * (10 mod 12 ) = 100000 mod 12;
    //(100 mod 12) * (100 mod 12) = 10000 mod 12;
    //(10 mod 12) * ( 10 mod 12) = 100 mod 12;
    if (B == 1)
        std::cout << "1" << std::endl;
    else
        std::cout << divide(A, B, C) << std::endl;
}

long long    divide(long long A, long long B, long long C) // power - 10 cur_val = 10 ^ 10
{
    if (B == 1)
        return ( A % C);
    else if (B % 2 != 0)
    {
        return ( ((divide(A, B - 1, C) % C ) * (divide(A, 1, C) % C)) % C);
    }
    else
        return ( ((divide(A, B / 2, C) % C ) * (divide(A, B / 2, C) % C)) % C);
}