/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 01:53:43 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/06 05:06:59 by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int data;
    struct s_node *next;
    struct s_node *prev;

} t_node;

typedef struct s_list_ps
{
    t_node  *head;
    int     size;
    t_node  *tail;
    
} t_list_ps;

//list_util.c
t_node	*create_node(int data);
void	pop_tail(t_list_ps *list);
void	pop_head(t_list_ps *list);
int	push_head(t_list_ps *list, int data);
 void	list_printer(t_list_ps *list);
int	push_tail(t_list_ps *list, int data);

//command.c
int sa(t_list_ps *list);

#endif