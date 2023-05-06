/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyepa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 12:05:29 by jinhyepa          #+#    #+#             */
/*   Updated: 2022/09/01 09:45:43 by jinhyepa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		dicerncharac(char a);
char	*make_upper(char *str);

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		index;

	index = 0;
	i = 0;
	str = make_upper(str);
	while (str[i])
	{
		if (dicerncharac(str[i]) && (str[i + 1] >= 'a' && str[i + 1] <= 'z'))
			str[i + 1] = str[i + 1] -32;
		else if ((str[i] >= 'a' && str[i] <= 'z') && i == 0)
			str[i] = str[i] -32;
		else
			str[i] = str[i];
		i++;
	}
	return (str);
}

char	*make_upper(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
		str[i] += 32;
		i++;
	}
	return (str);
}

int	dicerncharac(char ch)
{
	int		bl;

	bl = 0;
	if (ch < 48 || (ch >= 58 && ch <= 64))
		bl = 1;
	if ((ch >= 91 && ch <= 96) || (ch >= 123))
		bl = 1;
	return (bl);
}
