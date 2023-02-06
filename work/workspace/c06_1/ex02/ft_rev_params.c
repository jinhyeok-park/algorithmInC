/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <https://github.com/42Paris/42he  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:45:25 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/18 17:31:24 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	k;
	int	count;

	i = 0;
	count = argc - 1;
	if (argc-- > 1)
	{
		while (i < count)
		{
			k = 0;
			while (argv[argc][k] && argc > 0)
			{
				write(1, &argv[argc][k], 1);
				k++;
			}
			argc--;
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
