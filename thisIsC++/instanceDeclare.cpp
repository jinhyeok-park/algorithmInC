#include<iostream>

int main(void)
{
    // C++
    int a(0);
    int b(10);
    int c(b); // copy

    auto str("i am string");

    std::cout << a << " " << b << " " << c << std::endl;
    std::cout << str << std::endl;

}