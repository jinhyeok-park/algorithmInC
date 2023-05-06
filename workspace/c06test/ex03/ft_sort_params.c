/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:51:54 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/05 16:01:37 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_swap(char **src);

int	ft_strcmp(char *dest, char *src)
{
	int		i;

	i = 0;
	while (dest[i] || src[i])
	{
		if (dest[i] != src[i])
			return (dest[i] - src[i]);
		i++;
	}
	return (0);
}

void	print_f(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int ac, char *av[])
{
	int		i;

	if (ac > 1)
	{
		ft_swap(av);
		i = 1;
		while (av[i])
		{
			print_f(av[i]);
			i++;
			write(1, "\n", 1);
		}
	}
	return (0);
}

void	ft_swap(char **str)
{
	int		i;
	int		k;
	char	*temp;

	k = 1;
	temp = NULL;
	while (str[k])
	{
		i = k + 1;
		while (str[i])
		{
			if (ft_strcmp(str[k], str[i]) > 0)
			{
				temp = str[k];
				str[k] = str[i];
				str[i] = temp;
			}
			i++;
		}
		k++;
	}
}
