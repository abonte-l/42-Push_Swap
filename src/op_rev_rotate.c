/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:52:26 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:06:01 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rev_rotate(t_dlst *list)
{
	t_node	*tmp_c1;
	t_node	*tmp_c2;

	if (list == NULL || (list->head->prev == NULL && list->head->next == NULL))
		return ;
	tmp_c1 = list->tail;
	if (list->length == 2)
	{
		tmp_c1->next = list->head;
		tmp_c1->prev = NULL;
		list->head->next = NULL;
		list->head->prev = tmp_c1;
		list->tail = list->head;
		list->head = tmp_c1;
	}
	else
	{
		tmp_c2 = list->tail->prev;
		list->head->prev = tmp_c1;
		tmp_c1->next = list->head;
		list->head = tmp_c1;
		list->head->prev = NULL;
		list->tail = tmp_c2;
		tmp_c2->next = NULL;
	}	
}

void	rev_rotate_a(t_dlst *list)
{
	write(1, REV_ROTATE_A, 4);
	rev_rotate(list);
}

void	rev_rotate_b(t_dlst *list)
{
	write(1, REV_ROTATE_B, 4);
	rev_rotate(list);
}

void	double_rev_rotate(t_dlst *list_a, t_dlst *list_b)
{
	write(1, DOUBLE_REV_ROTATE, 4);
	rev_rotate(list_a);
	rev_rotate(list_b);
}
