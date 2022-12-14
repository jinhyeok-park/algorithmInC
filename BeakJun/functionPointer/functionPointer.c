#include<stdio.h>

typedef int (*funcptr)(int , int );

int plus(int num1, int num2)
{
    return num1 + num2;
}

int minus(int num1, int num2)
{
    return num1 - num2;
}

int division(int num1, int num2)
{
    return num1 / num2 + (num1 % num2);
}

int multiple(int num1, int num2)
{
    return num1 * num2;
}

int calculator(int num1, int num2, funcptr func)
{
    return func(num1,num2);
}

int main(int ac, char** av)
{
    funcptr calc = NULL;
    int a;
    int b;
    char op;

    scanf("%d  %c %d", &a , &op, &b);

    switch (op)
    {
    case '+' :
        calc = plus;
        break;
     case '-' :
        calc = minus;
        break;
     case '/' :
        calc = division;
        break;
     case '*' :
        calc = multiple;
        break;
    default:
        break;
    }

printf("this is %d." ,calculator(a,b,calc));

}