/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:09:56 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/06 11:58:23 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	destsize;
	unsigned int	srcsize;

	i = 0;
	k = 0;
	while (dest[i])
		i++;
	destsize = i;
	srcsize = ft_strlen(src);
	k = ft_strlen(src);
	if (size <= i)
		return (size + k);
	k = 0;
	while (src[k] && destsize + k + 1 < size)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	while (src[k])
		k++;
	return (destsize + srcsize);
}
