#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len) {
    //USING STACK , FIND SPECIAL POINT;
    int answer = 0;
    int* stack;
    int stackI; //stack index start -1;
    int     i;

    stackI = -1;
    stack = (int*)malloc(sizeof(int) * ingredient_len);
    i = 0;

    for (int j = 0; j < ingredient_len; j++)
    {
        stackI++;
        stack[stackI] = ingredient[j];// push ingredient

        if (stackI < 3)
            continue;

        if (stack[stackI - 3] == 1 && stack[stackI - 2] == 2 && stack[stackI - 1] == 3 && stack[stackI] == 1)
        {
            //pop
            for (int i = 0; i < 4; i++)
                stackI--;
            answer++;        }
    }
    return answer;
}