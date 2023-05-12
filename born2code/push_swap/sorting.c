/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinhyeok <jinhyeok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:15:01 by jinhyeok          #+#    #+#             */
/*   Updated: 2023/05/09 15:41:35by jinhyeok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_list_ps *lista)
{
	t_list_ps *listb;

	listb = create_list();
	if (!listb)
	{
		free_list(lista);
		exit(-1);
	}
	if (lista->size < 6)
		short_sorting(lista, listb);
	 else
	 	merge_sort(lista, listb);
}

int	*get_triangle(int depth, int size)
{
	int *ret;
	int	i;
	int arr_size;
	int	tri_size;

	tri_size = ft_pow(3, depth);
	ret = (int *)malloc(sizeof(int) * tri_size);
	ret[0] = size;
	arr_size = 1;

	while (depth--)
	{
		i = -1;
		while (++i < arr_size)
		{
			tri_size = ret[i];
			ret[i] = tri_size / 3;
			ret[arr_size + i] = tri_size / 3 + tri_size % 3;
			ret[arr_size * 2 + i] = tri_size / 3;
		}
		arr_size *= 3;
	}
	return (ret);
}

void	merge_sort(t_list_ps *lista, t_list_ps *listb)
{
	// make triangle 
	// triangle pattern 
	//traingle size; maximum tri size is 5 // fix value 
	// int *tri_size;
	// int	*tri_direction;
	//tri_size = make_tri_size(lista->size);
	int	dep;
	int	*sort_size;

	dep = depth(lista->size);
	while (dep)
	{
		sort_size = get_triangle(dep, lista->size);
		get_direction(sort_size, dep);
		sort_all(lista, listb, sort_size);
		free(sort_size);
		dep--;
	}
}

void	merge_to_b(t_list_ps *lista, t_list_ps *listb, int *sort_size)
{
	int	i;

	i = -1;
	while (i < lista->size)
	{
		if (sort_size[i] == 5 || sort_size[i] == -5)
			merge_5(lista, listb, sort_size[i]);
		else if (sort_size[i] == 4 || sort_size[i] == -4)
			merge_4(lista, listb, sort_size[i]);
		else if (sort_size[i] == 3 || sort_size[i] == -3)
			merge_3(lista, listb, sort_size[i]);
		else if (sort_size[i] == 2 || sort_size[i] == -2)
			merge_2(lista, listb, sort_size[i]);
		else
			pb(lista, listb, 1);
	}
}

void	merge_2(t_list_ps *lista, t_list_ps *listb, int size)
{
	if (size > 0)
	{
		if (lista->head->data > lista->tail->data)
		{
			pb(lista, listb, 1);
			rra(lista, 1);
		}
		else
		{
			rra(lista, 1);
			pb(lista, listb, 1);
		}
		pb(lista, listb, 1);
	}
	else
	{
		if (lista->head->data < lista->tail->data)
		{
			pb(lista, listb, 1);
			rra(lista, 1);
		}

	}
}

void	sort_all(t_list_ps *lista, t_list_ps *listb, int *sort_size)
{
	if (listb->size == 0)
	{
		merge_to_b(lista, sort_size);
	}
	else
	{

	}
}

int get_order(int idx)
{
    int flip;
    int range;
    int mirror;
    int dist;
    flip = 0;
    while (idx > 0)
    {
        range = 0;
        while (idx / ft_pow(3, range))
            range++;
        mirror = ft_pow(3, range - 1);
        dist = idx - mirror;
        dist %= mirror;
        idx = mirror - dist - 1;
        flip++;
    }
    return (flip);
}
void	get_direction(int *sort_size, int dep)
{
	int	tri_size;
	int	i;
	int	temp;

	i = -1;
	tri_size = ft_pow(3, dep);
	while (++i < tri_size)
	{
		temp = get_order(i);
		if (temp % 2 == 1)
			sort_size[i] *= -1;
	}
}


int ft_pow(int num, int power)
{
	int	ret;

	ret = 1;
	if (0 == power)
		return (1);
	if (num == 0)
		return (0);
	while (power--)
		ret *= num;
	return (ret);
}

int	depth(int size)
{
	int	depth;

	depth = 0;
	while (size)
	{
		if (size < 5)
			break;
		size = size / 3 + size % 3;
		depth++;
	}
	return (depth);
}

int	check_isbig(int *size_arr, int arr_s)
{
	int	i;

	i = -1;
	while (++i < arr_s)
	{
		if (size_arr[i] > 5)
			return (1);
	}
	return (0);
}

t_tri	*tri_create(void)
{
	t_tri *ret;

	ret = (t_tri *)malloc(sizeof(t_tri));
	if (!ret)
		return (NULL);
	ret->direction = NULL;
	ret->size = 0;
	ret->size_list = NULL;
	return (ret);
}

// int	*make_tri_size(int size)
// {
// 	// merge it all 3  left 2 value to be cat last triangle checker 
// 	int	i;
// 	int	size_malloc;

// }

void	short_sorting(t_list_ps *lista, t_list_ps *listb)
{
	if (lista->size == 2)
		sa(lista, 1);
	else if (lista->size == 3)
	  	sorting_3(lista);
	else if (lista->size == 4)
		sorting_4(lista, listb);
	else
		sorting_5(lista, listb);
}

void	sorting_5(t_list_ps *lista, t_list_ps *listb)
{
	push_minval_to_(lista, listb);
	sorting_4(lista, listb);
	pa(lista, listb, 1);
}

void	sorting_4(t_list_ps *lista, t_list_ps *listb)
{
	push_minval_to_(lista, listb);
	sorting_3(lista);
	pa(lista, listb, 1);
}
// find the minimum val and push to b

void	push_minval_to_(t_list_ps *lista, t_list_ps *listb)
{
	t_node *temp;
	int		min;
	int		i;

	temp = lista->head;
	min = temp->data;
	i = -1;
	while (++i < lista->size)
	{
		if (min > temp->data )
			min = temp->data;
		temp = temp->next;
	}
	i = val_index(lista, min);
	if (i < lista->size / 2)
		ra_p(lista, listb, min);
	else
		rra_p(lista, listb, min);
}

void	rra_p(t_list_ps *lista, t_list_ps *listb, int data)
{
	while (1)
	{
		if (lista->head->data == data)
		{
			pb(lista, listb, 1);
			break;
		}
		rra(lista, 1);
	}
}
void	ra_p(t_list_ps *lista, t_list_ps *listb, int data)
{
	while (1)
	{
		if (lista->head->data == data)
		{
			pb(lista, listb, 1);
			break;
		}
		ra(lista, 1);
	}

}

int	val_index(t_list_ps *list, int data)
{
	int	i;
	t_node *node;

	i = 0;
	node = list->head;
	while (i < list->size)
	{
		if (node->data == data)
			break;
		i++;
		node = node->next;
	}
	return (i);
}

void	sorting_45(t_list_ps *lista, t_list_ps *listb)
{
	while (1)
	{
		biggest_push_b(lista, listb);
		if (lista->size == 2)
		{
			if(lista->head->data > lista->head->next->data)
				sa(lista, 1);
			break;
		}
	}
	while (1)
	{
		merge_test(lista, listb);
		if (lista->size + listb->size <= lista->size)
		{
			if (issorting(lista))
				break;
		}
	}
}

int	issorting(t_list_ps *list)
{
	int		i;
	t_node	*temp;

	temp = list->head;
	i = 0;
	while (++i < list->size)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	biggest_push_b(t_list_ps *lista, t_list_ps *listb)
{
		// if (lista->size + listb->size < 6)
		// {
		// 	if (lista->size == 3 && listb->size == 2)
		// 	{
		// 		pb(lista, listb, 1);
		// 		return ;
		// 	}
		// }
		if (listb->size > 0)
		{
			if (find_max(lista, listb) == 1)
				sa(lista, 1);
			else if (find_max(lista, listb) == 2)
				rra(lista, 1);
			pb(lista, listb, 1);
			return ;
		}
		if (lista->tail->data > lista->head->data \
		&& lista->tail->data > lista->head->next->data)
			rra(lista, 1);
		else if (lista->head->next->data > lista->head->data \
		&&lista->head->next->data > lista->tail->data)
			sa(lista, 1);
		pb(lista, listb, 1);
}

int	find_max(t_list_ps *lista, t_list_ps *listb)
{
	int minimum;
	int	num[3];
	int	i;
	int	ret;

	num[0] = lista->head->data;
	num[1] = lista->head->next->data;
	num[2] = lista->tail->data;
	minimum = listb->head->data;
	i = 3;
	ret = 0;
	while (i--)
	{
		if (ret < num[i] && num[i] < minimum)
			ret = num[i];
	}
	if (num[0] == ret)
		return (0);
	else if (num[1] == ret)
		return (1);
	return (2);
}

void	merge_test(t_list_ps *lista, t_list_ps *listb)
{
	if (lista->tail->data > listb->head->data \
	&&lista->tail->data > listb->tail->data)
	{
		rra(lista, 1);
		return ;
	}
	else if (listb->tail->data > listb->head->data \
	&& listb->tail->data > lista->tail->data)
		rrb(listb, 1);
	pa(lista, listb, 1);
	if (lista->size + listb->size == lista->size)
		rra(lista, 1);
}

void	sorting_3(t_list_ps *list)
{
	int	index;
	
	index = index_changer(list);
	if (index == 132)
	{
		sa(list, 1);
		ra(list, 1);
	}
	else if (index == 213)
		sa(list, 1);
	else if (index == 231)
		rra(list, 1);
	else if (index == 321)
	{
		sa(list, 1);
		rra(list, 1);
	}
	else
		ra(list, 1);
}

int	index_changer(t_list_ps *list)
{
	int temp1; 
	int temp2;
	int temp3;

	temp1 = list->head->data;
	temp2 = list->head->next->data;
	temp3 = list->tail->data;
	if (temp1 < temp2 && temp1 < temp3)
		return (132);
	else if (temp1 > temp2 && temp1 > temp3 && temp2 < temp3)
		return (312);
	else if (temp1 > temp2 && temp2 > temp3)
		return (321);
	else if (temp2 < temp3)
		return (213);
	else
		return (231);
}

// int	merge_sort(t_list_ps *lista, t_list_ps *listb)
// {
// 	int		size;
// 	t_tri	*tri_info;

// 	size = lista->size;
// 	tri_info = (t_tri *)malloc(sizeof(t_tri));
// 	if (!tri_info)
// 	{
// 		free_list(list);
// 		exit(1);
// 	}
// 	tri_info->size_list = NULL;
// 	set_tri_info(size, list, tri_info);
// }

// int set_tri_info(int size, t_list_ps *list, t_tri *tri_info)
// {
// 	int	*cur_size;
// 	int	i;

// 	i = 3;
// 	if (size > 5)
// 	{
// 		cur_size = size_split(size);
// 		while (i--)
// 			set_tri_info(cur_size[i], list, tri_info);
// 	}
// 	if(!set_size(size, tri_info))
// 	{

// 	}
// }

// int	set_size(int size, t_tri *tri_info)
// {
// 	int	i;

// 	i = 0;
// 	if (!tri_info->size_list)
// 	{
// 		tri_info->size_list = (int *)malloc(sizeof(int));
// 		if (!tri_info->size_list)
// 			return (0);
// 		tri_info->size = 1;
// 		tri_info->size_list[0] = size;
// 	}
// 	else
// 	{
// 		tri_info->size_list = copy_cat(tri_info->size_list, tri_info->size, size);
// 		if (tri_info->size)
// 		tri_info->size++;
// 	}
// 	return (1);
// }

// int	*copy_cat(int *arr, int size, int val)
// {
// 	int	i;
// 	int	*ret;

// 	i = -1;
// 	ret = (int *)malloc(sizeof(int) * size + 1);
// 	if (!ret)
// 		return (NULL);
// 	while (++i < size)
// 		ret[i] = arr[i];
// 	ret[i] = val;
// 	free(arr);
// 	return (ret);
// }

int *size_split(int size)
{
	int i;

	i = -1;
	int *ret;
	int midval = size / 3;
	ret = (int *)malloc(sizeof(int));
	if (!ret)
		return (0);
	while (++i < 3)
		ret[i] = midval;
	while ((ret[0] + ret[1] + ret[2]) != size)
	{
		ret[1] += 1;
	}
	return (ret);
}


// #include <stdio.h>
// int main(void)
// {
// 	int *ret;

// 	ret = size_split(100);
// 	for (int i = 0 ; i < 3; i++)
// 	{
// 		printf("%d", ret[i]);
// 	}
// }