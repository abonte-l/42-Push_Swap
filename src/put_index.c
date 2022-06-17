/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:17:35 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:11:03 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_index_a(t_dlst *list_a, t_dlst *index)
{
	struct s_node	*p_temp;

	if (index != NULL)
	{
		p_temp = list_a->head;
		while (p_temp != NULL)
		{
			if (index->head->data == p_temp->data)
			{
				p_temp->index = index->head->index;
				p_temp = p_temp->next;
			}
			else
				rotate_a_index(index);
		}
	}	
}
