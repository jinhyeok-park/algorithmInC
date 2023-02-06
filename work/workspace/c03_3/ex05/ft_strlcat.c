/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 10:23:48 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/01/17 10:41:10 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	result;

	i = 0;
	k = 0;
	dest_len = ft_len(dest);
	src_len = ft_len(src);
	result = src_len + dest_len;
	if (dest_len > size)
		return (src_len + size);
	while (dest[i])
		i++;
	while (src[k] != '\0' && k + dest_len + 1 < size)
	{
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (result);
}
