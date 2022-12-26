#include<stdio.h>
#include<stdlib.h>

int My_abs(int num)
{
	if (num < 0)
    		return (num * -1);
	return (num);
}

int Promising(int* arr, int curRow)
{
	int i = 0;

	while (i < curRow)
	{
		//체크 조건 열이 겹쳤을떄, 대가선열에 겹쳤을떄 우방향 좌방향 ;
		if (arr[i] == arr[curRow] || My_abs(arr[i] - arr[curRow]) == My_abs(i - curRow))
		{
			printf("대입을 취소함 \n");
			return (0);
		}
		i++;
	}
	return (1);
}

void N_queens(int N, int* arr, int row)
{
	int answer = 0;
	int col = 0;

	if (Promising(arr, row))
	{
		if (row == N - 1)
		{
			answer++;
			printf("현재 %d\n", answer);
		}
		else
		{
			while (col < N)
			{
				arr[row + 1] = col;
				printf("%d 행에 %d 열에 위치시킵니다. \n", row + 1, col);
				N_queens(N, arr, row + 1);
				col++;
			}
			// 다음행에 값을 대입해준다. 
		}
	}
	
}

int main(void)
{
	int* arr;
	int N = 9;
	arr = malloc(sizeof(int) * N);
	
	N_queens(N, arr, -1);

}