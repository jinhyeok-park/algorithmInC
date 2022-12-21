#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include "./ex00/ft_foreach.c"
#include "./ex01/ft_map.c"
#include "./ex02/ft_any.c"
#include "./ex03/ft_count_if.c"
#include "./ex04/ft_is_sort.c"
#include "./ex06/ft_sort_string_tab.c"
#include "./ex07/ft_advanced_sort_string_tab.c"
void	ft_putnbr(int num)
{
	printf("%d\n",num);// 여러분은 여러분이 짜신 putnbr넣어보세요 ㅎㅎ
}//ex00

int	plus(int num)
{
	return(num + 10);
}//ex01

int check_num(char *arr)
{
	while (*arr)
	{
		if ('0' <= *arr && *arr <= '9')
			return (0);
		arr++;
	}
	return (1);
}//ex02 ex03

int	cmp(int a,int b)
{
	if (a < b)
		return (-1);
	else if (a > b)
		return (1);
	else
		return (0);
}//ex04 

int	ft__strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}//ex07

int	main()
{
	{

		printf("\n----------------------ex00----------------------------\n");
		int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		ft_foreach(arr, 10, ft_putnbr);

	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{

		printf("\n----------------------ex01----------------------------\n");
		int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int *result = ft_map(arr, 10, plus);
		for(int i = 0; i < 10 ; i++)
			printf("result ::: arr[%d] :: %d\n",i,result[i]);

	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요

	{
		printf("\n----------------------ex02----------------------------\n");
		char *arr[7];
		arr[0] = "012345";
		arr[1] = "0325";
		arr[2] = "123";
		arr[3] = "678";
		arr[4] = "0";
		arr[5] = 0;
		for(int i = 0; i < 5; i++)
			printf("arr[%d] ::::%s\n",i,arr[i]);
		printf("\n\nresult:::: %d\n",ft_any(arr, check_num));
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex03----------------------------\n");
		char *arr[7];
		arr[0] = "012345";
		arr[1] = "0325";
		arr[2] = "123";
		arr[3] = "678";
		arr[4] = "cccc";
		arr[5] = "aaaa";
		for(int i = 0; i < 6; i++)
			printf("arr[%d] ::::%s\n",i,arr[i]);
		printf("\n\nresult:::: %d\n",ft_count_if(arr, 6, check_num));
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex04----------------------------\n");
		int tab[100] = {1,4,5,6,7,10,16};//7
		for(int i = 0; i < 7; i++)
			printf("tab[%d] ::::%d\n",i,tab[i]);
		printf("\nresult::::%d\n\n\n" ,ft_is_sort(tab, 7, cmp));


	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex05----------------------------\n");
		printf("\n\n\nMAKEFILE은 직접해봅시다!!!\n\n\n\n");
		
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex06----------------------------\n");

		char *arr[7];
		arr[0] = "hi";
		arr[1] = "my";
		arr[2] = "name";
		arr[3] = "is";
		arr[4] = "joushin";
		arr[5] = "aaaa";
		arr[6] = 0;
		for (int i = 0; i < 6; i++)
		{
			printf("before ::::::arr[%d] :: %s\n",i, arr[i]);
		}
		ft_sort_string_tab(arr);
		printf("\n\n\nafter\n\n\n\n");
		for (int i = 0; i < 6; i++)
		{
			printf("after ::::::arr[%d] :: %s\n",i, arr[i]);
		}
		
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	{
		printf("\n----------------------ex07----------------------------\n");
		char *arr[7];
		arr[0] = "hi";
		arr[1] = "my";
		arr[2] = "name";
		arr[3] = "is";
		arr[4] = "joushin";
		arr[5] = "aaaa";
		arr[6] = 0;
		for (int i = 0; i < 6; i++)
		{
			printf("before ::::::arr[%d] :: %s\n",i, arr[i]);
		}
		printf("\n\n\nafter\n\n\n\n");
		ft_advanced_sort_string_tab(arr,ft__strcmp);
		for (int i = 0; i < 6; i++)
		{
			printf("after ::::::arr[%d] :: %s\n",i, arr[i]);
		}
		
	}//직접 바꿔서 사용해보세요 다양한 값을 넣어보세요
	return (0);	
}
