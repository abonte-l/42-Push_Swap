/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iznogoud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:25:08 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/15 23:08:17 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	iznogoud(t_dlst *list)
{
	t_node	*node_1;
	t_node	*node_2;

	node_1 = list->tail;
	node_2 = list->head;
	while (node_2 != NULL)
	{
		if (node_2->data > node_1->data || node_1->data == list->max)
		{
			node_1 = node_2;
			node_2 = node_2->next;
		}
		else
		{
			return (IZNOGOUD);
		}
	}
	return (IZGOUD);
}
