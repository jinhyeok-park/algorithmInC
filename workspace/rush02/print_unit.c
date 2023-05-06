#include <unistd.h>
#include <stdio.h>

char *thousands[] = {"", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion",
	"sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion"};

char *ones[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char *teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char *tens[] = {"0", "0", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
char *hundred[] = {"hundred"};

int	cnt_dict_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
		i++;
	printf("len = %d\n", i);
	return (i);
}

void	ft_print_char(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{	
		write(1, &str[i], 1);
		i++;
	}
	write(1, " ", 1);
}

int	print_unit(char *str, int print_zero)
{
	if (print_zero)
		ft_print_char(ones[0]);
	if (str[0] != '0')
	{
		ft_print_char(ones[str[0] - '0']);
		ft_print_char(hundred[0]);
	}
	if (str[1] != '0')
	{
		if (str[1] == '1')
		{
			ft_print_char(teens[str[2] - '0']);
			return (1);
		}
		else
			ft_print_char(tens[str[1] - '0']);
	}
	if (str[2] != '0')
		ft_print_char(ones[str[2] - '0']);
	return (1);
}

int	check_if_zeros(char *nums)
{
	int	cnt_zero;

	cnt_zero = 0;
	while (*nums)
	{
		if (*nums == '0')
			cnt_zero++;
		nums++;
	}
	if (cnt_zero == 3)
		return (1);
	return (0);
}

int	print_full_num(char **nums)
{
	int	len;
	int	i;

	i = 0;
	len = cnt_dict_nums(nums);
	if (len == 0) //입력이 빈 경우
		return (0);
	if (len == 1 && check_if_zeros(nums[0])) // "000"이 입력된 경우
	{
		ft_print_char(ones[0]);
		return (0);
	}
	while (len > 0)
	{
		if (check_if_zeros(nums[i]) == 0)
		{
			print_unit(nums[i], 0);
			ft_print_char(thousands[len - 1]);
		}
		len--;
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	char *tmp[] = { "010","000","111","000","000","000","000","000","000","000","000","000","000", 0};
	print_full_num(tmp);
	(void)argc;
	(void)argv;
	return (0);
}
