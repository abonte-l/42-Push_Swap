/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minamax.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:46:36 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:02:25 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_minamax_list(t_dlst *list, t_node *pos)
{
	pos = list->head;
	list->max = list->head->data;
	list->min = list->head->data;
	while (pos != NULL)
	{
		if (pos->data > list->max)
			list->max = pos->data;
		else if (pos->data < list->min)
			list->min = pos->data;
		pos = pos->next;
	}
}

void	find_minamax(t_dlst *list_a, t_dlst *list_b)
{
	t_node	*pos;

	pos = NULL;
	if (list_a->head != NULL)
	{
		find_minamax_list(list_a, pos);
	}
	if (list_b->head != NULL)
	{
		find_minamax_list(list_b, pos);
	}
}

int	find_min(t_dlst *list_a, int pos_min)
{
	t_node	*p_pos;

	p_pos = NULL;
	pos_min = 1;
	if (list_a)
	{
		p_pos = list_a->head;
		while (p_pos != NULL && p_pos->data != list_a->min)
		{
			p_pos = p_pos->next;
			pos_min++;
		}
	}
	return (pos_min);
}

void	minamax_start(t_dlst *list, int data)
{
	list->max = data;
	list->min = data;
	return ;
}

void	minamax(t_dlst *list, int data)
{
	if (data > list->max)
		list->max = data;
	else if (data < list->min)
		list->min = data;
	return ;
}
