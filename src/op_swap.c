/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 13:59:46 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:09:39 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_dlst *list)
{
	t_node	*tmp_c1;
	t_node	*tmp_c2;

	if (list == NULL || (list->head->prev == NULL && list->head->next == NULL))
		return ;
	tmp_c1 = list->head->next;
	if (list->length == 2)
	{
		list->head->next = NULL;
		list->head->prev = tmp_c1;
		tmp_c1->prev = NULL;
		tmp_c1->next = list->head;
		list->tail = list->head;
		list->head = tmp_c1;
	}
	else
	{
		tmp_c2 = tmp_c1->next;
		tmp_c2->prev = list->head;
		list->head->next = tmp_c2;
		list->head->prev = tmp_c1;
		tmp_c1->prev = NULL;
		tmp_c1->next = list->head;
		list->head = tmp_c1;
	}
}

void	swap_a(t_dlst *list)
{
	write(1, SWAP_A, 3);
	swap(list);
}

void	swap_b(t_dlst *list)
{
	write(1, SWAP_B, 3);
	swap(list);
}

void	double_swap(t_dlst *list_a, t_dlst *list_b)
{
	write(1, DOUBLE_SWAP, 3);
	swap(list_a);
	swap(list_b);
}
