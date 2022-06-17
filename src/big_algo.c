/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:06:15 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 16:10:59 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_in_a(t_dlst *list, t_stages *stages, t_piles *pile)
{
	t_node	*i_pos_head;
	t_node	*i_pos_tail;

	if (list && list->head && list->tail)
	{
		i_pos_head = list->head;
		i_pos_tail = list->tail;
		while (!((i_pos_head->index >= pile->low_min && i_pos_head->index
					<= pile->low_max) || (i_pos_head->index >= pile->top_min
					&& i_pos_head->index <= pile->top_max)))
		{
			if (i_pos_head->next == NULL)
				return (FALSE);
			i_pos_head = i_pos_head->next;
			stages->pos_head++;
		}
		while (!((i_pos_tail->index >= pile->low_min && i_pos_tail->index
					<= pile->low_max) || (i_pos_tail->index >= pile->top_min
					&& i_pos_tail->index <= pile->top_max)))
		{
			i_pos_tail = i_pos_tail->prev;
			stages->pos_tail++;
		}
	}
	return (TRUE);
}

void	init_pile(t_piles *pile, t_stages *stages)
{
	int	pile_len;

	pile_len = stages->list_len / stages->nb_pile;
	pile->top_min = (pile->top_num - 1) * pile_len + 1;
	pile->top_max = pile->top_num * pile_len;
	pile->low_min = (pile->low_num - 1) * pile_len + 1;
	pile->low_max = pile->low_num * pile_len;
}

void	algo_pile(t_piles *pile, t_stages *stages, t_dlst *list_a,
t_dlst *list_b)
{
	while (find_in_a(list_a, stages, pile) == TRUE)
	{
		if (stages->pos_head <= stages->pos_tail)
		{
			while (stages->pos_head > 1)
			{
				rotate_a(list_a);
				stages->pos_head--;
			}
		}
		else
		{
			while (stages->pos_tail > 0)
			{
				rev_rotate_a(list_a);
				stages->pos_tail--;
			}
		}
		push_b(list_a, list_b);
		if (list_b->head->index <= pile->low_max && list_b->length > 1)
			rotate_b(list_b);
		re_init_stages(stages);
	}
	return ;
}

void	big_algo(t_dlst *list_a, t_dlst *list_b, t_stages *stages)
{
	t_piles	*pile;

	pile = NULL;
	pile = malloc(sizeof * pile);
	init_stages(stages, list_a);
	pile->top_num = stages->nb_pile / 2 + 1;
	pile->low_num = stages->nb_pile / 2;
	while (pile->low_num > 0)
	{
		init_pile(pile, stages);
		algo_pile(pile, stages, list_a, list_b);
		pile->top_num++;
		pile->low_num--;
	}
	med_algo(list_a, list_b);
	free(pile);
	pile = NULL;
}
