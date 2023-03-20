/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:41:00 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/03/20 14:47:36 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*throw;

	if (!lst || !del || !(*lst))
		return ;
	temp = *lst;
	while (temp)
	{
		throw = temp;
		temp = temp->next;
		ft_lstdelone(throw, del);
	}
	*lst = 0;
}
