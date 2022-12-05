#include<stdio.h>

int main(void)
{
    int input;
    int answer;

    scanf_s("%d" , &input);
    answer = Fibonacci(input);
    printf("%d" , answer);

    return (0);
}

int Fibonacci(int num)
{
    if (num < 1)
        return (0);
    else if (num == 1)
        return (1);
    return (Fibonacci(num - 1) + Fibonacci(num - 2));   
}