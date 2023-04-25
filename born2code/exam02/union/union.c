#include <unistd.h>

int check_self(char *str, char c, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	check_each(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		int	i;

		i = 0;
		while (av[1][i])
		{
			if (check_self(av[1], av[1][i], i))
				write(1, &av[1][i], 1);
			i++;
		}
		i = 0;
		while (av[2][i])
		{
			if (check_each(av[1], av[2][i]))
			{
				if (check_self(av[2], av[2][i], i))
					write(1, &av[2][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
