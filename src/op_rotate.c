/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:08:47 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:07:15 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_dlst *list)
{
	t_node	*tmp_c1;
	t_node	*tmp_c2;

	if (list == NULL || (list->head->prev == NULL && list->head->next == NULL))
		return ;
	tmp_c1 = list->head;
	if (list->length == 2)
	{
		tmp_c1->next = NULL;
		list->head = list->tail;
		list->tail = tmp_c1;
		list->head->prev = NULL;
		list->head->next = list->tail;
		list->tail->prev = list->head;
	}
	else
	{
		tmp_c2 = list->head->next;
		list->tail->next = tmp_c1;
		tmp_c1->prev = list->tail;
		list->tail = tmp_c1;
		list->tail->next = NULL;
		list->head = tmp_c2;
		tmp_c2->prev = NULL;
	}
}

void	rotate_a(t_dlst *list)
{
	write(1, ROTATE_A, 3);
	rotate(list);
}

void	rotate_b(t_dlst *list)
{
	write(1, ROTATE_B, 3);
	rotate(list);
}

void	double_rotate(t_dlst *list_a, t_dlst *list_b)
{
	write(1, DOUBLE_ROTATE, 3);
	rotate(list_a);
	rotate(list_b);
}
