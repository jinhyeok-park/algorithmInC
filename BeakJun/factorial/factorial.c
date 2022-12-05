#include<stdio.h>

int main(void) //while 
{
    int input;
    int answer;

    scanf("%d", &input);
    answer = 1;
    input++;
    while (--input > 0)
        answer *= input;
    printf("%d", answer);
    return (0);
}
int main(void) // recursive
{
	int input;
	int answer;

	scanf_s("%d", &input);
	answer = factorial(input);
	printf("%d", answer);
}

int factorial(int num)
{
	if (num <= 1)
		return (1);
	else
		return(num * factorial(num - 1));
}