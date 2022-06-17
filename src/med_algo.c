/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:43:32 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:18:33 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_pospush(t_dlst *list_a, t_dlst *list_b, int pos_push)
{
	t_node	*p_pos;

	p_pos = NULL;
	pos_push = 1;
	if (list_a)
	{
		p_pos = list_a->head;
		while (p_pos->next != NULL && (!((p_pos->data < list_b->head->data)
					&& (p_pos->next->data > list_b->head->data))))
		{
			p_pos = p_pos->next;
			pos_push++;
		}
	}
	return (pos_push);
}

void	put_back_a_if(t_dlst *list_a, t_dlst *list_b, int pos_min)
{
	pos_min = find_min(list_a, pos_min);
	while (list_a->head->data != list_a->min)
	{
		if (pos_min >= (list_a->length / 2 + 1))
			rev_rotate_a(list_a);
		else
			rotate_a(list_a);
	}
	push_a(list_a, list_b);
	find_minamax(list_a, list_b);
}

void	put_back_a_else(t_dlst *list_a, t_dlst *list_b, int pos_push)
{
	pos_push = find_pospush(list_a, list_b, pos_push) + 1;
	list_a->len_tmp = list_a->length;
	while (!(list_b->head->data < list_a->head->data
			&& list_b->head->data > list_a->tail->data) && list_a->len_tmp >= 0)
	{
		if (pos_push > (list_a->length / 2 +1))
		{
			rev_rotate_a(list_a);
			list_a->len_tmp--;
		}
		else
		{
			rotate_a(list_a);
			list_a->len_tmp--;
		}
	}
	push_a(list_a, list_b);
	find_minamax(list_a, list_b);
}

void	put_back_a(t_dlst *list_a, t_dlst *list_b, int pos_min)
{
	int	pos_push;

	pos_push = 0;
	if (list_b->head->data > list_a->max || list_b->head->data < list_a->min)
		put_back_a_if(list_a, list_b, pos_min);
	else
		put_back_a_else(list_a, list_b, pos_push);
}

void	med_algo(t_dlst *list_a, t_dlst *list_b)
{
	int	pos_min;

	pos_min = 0;
	init_minamax(list_a);
	while (list_a->length > 3)
	{
		push_b(list_a, list_b);
		find_minamax(list_a, list_b);
	}
	algo_3(list_a);
	while (list_b->head != NULL)
		put_back_a(list_a, list_b, pos_min);
	pos_min = find_min(list_a, pos_min);
	while (list_a->head->data != list_a->min)
	{
		if (pos_min > (list_a->length / 2 + 1))
			rev_rotate_a(list_a);
		else
			rotate_a(list_a);
	}
	return ;
}
