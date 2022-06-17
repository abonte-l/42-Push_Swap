/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_index_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:24:04 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:25:48 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_pospush_index(t_dlst *index, t_dlst *list_b)
{
	t_node	*p_pos;

	p_pos = NULL;
	index->pos_push = 1;
	if (index)
	{
		p_pos = index->head;
		while (p_pos->next != NULL && (!((p_pos->data < list_b->head->data)
					&& (p_pos->next->data > list_b->head->data))))
		{
			p_pos = p_pos->next;
			index->pos_push++;
		}
	}
	return (index->pos_push);
}
