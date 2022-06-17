/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fonctions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:45:29 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 10:59:40 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_minamax(t_dlst *list)
{
	list->max = 0;
	return ;
}

void	init_stages(t_stages *stages, t_dlst *list)
{
	int	nb_pile;

	nb_pile = stages->nb_pile;
	stages->current_pile = 1;
	stages->current_stage = list->length * stages->current_pile / nb_pile;
	stages->counter_stage = stages->current_stage;
	stages->pos_head = 1;
	stages->pos_tail = 1;
	stages->list_len = list->length;
}

void	re_init_stages(t_stages *stages)
{
	stages->pos_head = 1;
	stages->pos_tail = 1;
}

void	init_index(t_dlst *list_b, t_dlst *index)
{
	struct s_node	*p_temp;
	int				index_n;

	med_algo_index(index, list_b);
	index_n = 1;
	if (index != NULL )
	{
		p_temp = index->head;
		while (p_temp != NULL)
		{
			p_temp->index = index_n;
			p_temp = p_temp->next;
			index_n++;
		}
	}
}
