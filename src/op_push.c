/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:20:39 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 16:14:34 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_dlst *list_from, t_dlst *list_to)
{
	t_node	*tmp_c1;

	tmp_c1 = list_from->head;
	if (list_from->length == 1)
	{
		list_from->head = NULL;
		list_from->tail = NULL;
	}
	else
	{
		list_from->head = list_from->head->next;
		list_from->head->prev = NULL;
	}
	if (list_to == NULL || (list_to != NULL && list_to->length == 0))
	{
		tmp_c1->next = NULL;
		list_to->tail = tmp_c1;
	}
	else
	{
		tmp_c1->next = list_to->head;
		list_to->head->prev = tmp_c1;
	}
	list_to->head = tmp_c1;
	return ;
}

void	push_a(t_dlst *list_a, t_dlst *list_b)
{
	if (list_b == NULL)
		return ;
	push(list_b, list_a);
	list_a->length++;
	list_b->length--;
	write(1, PUSH_A, 3);
	return ;
}

void	push_b(t_dlst *list_a, t_dlst *list_b)
{
	if (list_a == NULL)
		return ;
	push(list_a, list_b);
	list_b->length++;
	list_a->length--;
	write(1, PUSH_B, 3);
	return ;
}
