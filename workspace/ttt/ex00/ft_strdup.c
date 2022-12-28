/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:51:33 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/06 15:07:52 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	str_len(char *src)
{
	int		i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*result;
	char	*temp;
	int		src_len;

	src_len = str_len(src);
	temp = (char *)malloc(sizeof(char) * src_len + 1);
	if (!temp)
		return (0);
	result = temp;
	while (*src)
	{
		*temp = *src;
		temp++;
		src++;
	}
	*temp = '\0';
	return (result);
}
