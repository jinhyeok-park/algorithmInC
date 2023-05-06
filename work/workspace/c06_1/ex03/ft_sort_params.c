/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:15:32 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/18 19:23:33 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	ft_cmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_print(char **av)
{
	int	i;
	int	k;

	i = 1;
	while (av[i])
	{
		k = 0;
		while (av[i][k])
		{
			write(1, &av[i][k], 1);
			k++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		k;
	char	*temp;

	i = 0;
	if (ac > 1)
	{
		while (i < ac - 1)
		{
			k = 1;
			while (k < ac - i - 1)
			{
				if (ft_cmp(av[k], av[k + 1]) > 0)
				{
					temp = av[k];
					av[k] = av[k + 1];
					av[k + 1] = temp;
				}
				k++;
			}
			i++;
		}
		ft_print(av);
	}
	return (0);
}
