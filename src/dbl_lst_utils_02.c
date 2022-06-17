/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_utils_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:20:32 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 10:57:34 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	new_node_start(t_dlst *list, t_node *new_node, int data)
{
	if (new_node != NULL)
	{
		new_node->data = data;
		new_node->prev = NULL;
		if (list->tail == NULL)
		{
			new_node->next = NULL;
			list->head = new_node;
			list->tail = new_node;
		}
		else
		{
			list->head->prev = new_node;
			new_node->next = list->head;
			list->head = new_node;
		}
		list->length++;
	}
}

void	new_node_end(t_dlst *list, t_node *new_node, int data)
{
	if (new_node != NULL)
	{
		new_node->data = data;
		new_node->next = NULL;
		if (list->tail == NULL)
		{
			new_node->prev = NULL;
			list->head = new_node;
			list->tail = new_node;
		}
		else
		{
			list->tail->next = new_node;
			new_node->prev = list->tail;
			list->tail = new_node;
		}
		list->length++;
	}
}

void	dlist_delete(t_dlst **list)
{
	struct s_node	*pos_tmp;
	struct s_node	*pos_del;

	if (*list != NULL)
	{
		pos_tmp = (*list)->head;
		while (pos_tmp != NULL)
		{
			pos_del = pos_tmp;
			pos_tmp = pos_tmp->next;
			free(pos_del);
		}
		free(*list);
		*list = NULL;
	}
}
