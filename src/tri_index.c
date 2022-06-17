/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:16:15 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:26:29 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_3_index(t_dlst *list)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = list->head->data;
	v2 = list->head->next->data;
	v3 = list->tail->data;
	if (v1 > v2 && v1 > v3)
		rotate_a_index(list);
	else if (v2 > v1 && v2 > v3)
		rev_rotate_a_index(list);
	else if (v1 > v2)
		swap_a_index(list);
	else
		return ;
	algo_3_index(list);
	return ;
}

void	put_back_a_if_idx(t_dlst *index, t_dlst *list_b, int pos_min)
{
	pos_min = find_min(index, pos_min);
	while (index->head->data != index->min)
	{
		if (pos_min >= (index->length / 2 + 1))
			rev_rotate_a_index(index);
		else
			rotate_a_index(index);
	}
	push_a_index(index, list_b);
	find_minamax(index, list_b);
}

void	put_back_a_index(t_dlst *index, t_dlst *list_b, int pos_min)
{
	index->pos_push = 0;
	if (list_b->head->data > index->max || list_b->head->data < index->min)
		put_back_a_if_idx(index, list_b, pos_min);
	else
	{
		index->pos_push = find_pospush_index(index, list_b) + 1;
		index->len_tmp = index->length;
		while (!(list_b->head->data < index->head->data && list_b->head->data
				> index->tail->data) && index->len_tmp >= 0)
		{
			if (index->pos_push >= (index->length / 2 + 1))
			{
				rev_rotate_a_index(index);
				index->len_tmp--;
			}		
			else
			{
				rotate_a_index(index);
				index->len_tmp--;
			}
		}
		push_a_index(index, list_b);
		find_minamax(index, list_b);
	}
}

void	turn_index(int pos_min, t_dlst *index)
{
	if (pos_min >= (index->length / 2 + 1))
	{
		rev_rotate_a_index(index);
		index->len_tmp--;
	}										
	else
	{
		rotate_a_index(index);
		index->len_tmp--;
	}
}

void	med_algo_index(t_dlst *index, t_dlst *list_b)
{
	int	pos_min;

	init_minamax(index);
	while (index->length > 3)
	{
		push_b_index(index, list_b);
		find_minamax(index, list_b);
	}
	algo_3_index(index);
	while (list_b->head != NULL)
	{
		put_back_a_index(index, list_b, pos_min);
		pos_min = find_min(index, pos_min);
		index->len_tmp = index->length;
		while (index->head->data != index->min)
			turn_index(pos_min, index);
	}
	return ;
}
