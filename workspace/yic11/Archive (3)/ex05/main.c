/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yim <yim@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:16:22 by yim               #+#    #+#             */
/*   Updated: 2022/09/11 21:51:44 by yim              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	void	(*f[1])(char **argv);

	f[0] = do_op;
	if (argc == 4)
	{
		if (argv[2][1] != '\0')
		{
			ft_putnbr(0);
			ft_putchar('\n');
			return (0);
		}
		(*f[0])(argv);
	}
}