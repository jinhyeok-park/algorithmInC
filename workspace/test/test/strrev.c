#include<unistd.h>
#include<stdio.h>

char	*ft_strrev(char *str)
{
	int i;
	int k;
	char temp;

	i = 0;
	k = 0;
	while (str[i])
		i++;
	while (k < i / 2)
	{
		temp = str[k];
		str[k] = str[i - k - 1];
		str[i - k - 1] = temp;
		k++;
	}
	return (str);
}
int main(void)
{
	char str[10] = "string";
	ft_strrev(str);
	printf("%s" , str);
}


	
