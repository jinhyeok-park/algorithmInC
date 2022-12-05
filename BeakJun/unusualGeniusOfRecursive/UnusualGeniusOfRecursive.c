#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main(void)
{
    int count;
    int     i;
    char str[1000][1000];
    int num1;
    
    i = 0;
    num1 = 0;
    scanf_s("%d", &count);

    while (i < count)
    {
        scanf_s(" %s", str[i], sizeof(str[i]));
        i++;
    }
    i = 0;
    while (i < count)
    {
        isPalindrome(str[i]);
        i++;
    }
}

int recursion(const char* s, int l, int r, int count) 
{
    count++;
    if (l >= r)
    {
        printf("%d ", 1);
        printf("%d\n", count);
        return 1;
    }
    else if (s[l] != s[r])
    {
        printf("%d ", 0);
        printf("%d\n", count);
        return 0;
    }
    else 
        return recursion(s, l + 1, r - 1, count);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1,0);
}