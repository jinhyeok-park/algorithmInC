/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:16:34 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/03 12:25:18 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	ft_strlength(char *arr);

unsigned int	copystr(char *dest, char *src, unsigned int size)
{
	int		a;
	int		i;

	a = ft_strlength(src);
	i = 0;
	if ((int)size > a)
	{
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	else if ((int)size <= a)
	{	
		while (i < (int)size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return ((unsigned int)a);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	if (!dest || !src)
		return (0);
	return (copystr(dest, src, size));
}

int	ft_strlength(char *arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
