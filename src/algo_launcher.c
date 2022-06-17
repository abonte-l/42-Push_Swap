/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_launcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:37:22 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 16:21:29 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	big_algo_launcher_b(t_dlst *list_a, t_dlst *list_b, t_stages *stages)
{
	if (list_a->length > 100 && list_a->length <= 300)
	{
		stages->nb_pile = 21;
		big_algo(list_a, list_b, stages);
	}
	else if (list_a->length > 300 && list_a->length <= 500)
	{
		stages->nb_pile = 31;
		big_algo(list_a, list_b, stages);
	}
	else if (list_a->length > 500)
	{
		stages->nb_pile = 37;
		big_algo(list_a, list_b, stages);
	}
}

void	big_algo_launcher_a(t_dlst *list_a, t_dlst *list_b, t_stages *stages)
{
	if (list_a->length > 11 && list_a->length <= 59)
	{
		stages->nb_pile = 7;
		big_algo(list_a, list_b, stages);
	}
	else if (list_a->length > 59 && list_a->length <= 100)
	{
		stages->nb_pile = 11;
		big_algo(list_a, list_b, stages);
	}
}

void	big_algo_dispatch(t_dlst *list_a, t_dlst *list_b, t_dlst *index,
t_stages *stages)
{
	init_index(list_b, index);
	put_index_a(list_a, index);
	if (list_a->length > 11 && list_a->length <= 100)
		big_algo_launcher_a(list_a, list_b, stages);
	else if (list_a->length > 100)
		big_algo_launcher_b(list_a, list_b, stages);
}

void	algo_launcher(t_dlst *list_a, t_dlst *list_b, t_dlst *index)
{
	t_stages	*stages;

	stages = NULL;
	stages = malloc(sizeof * stages);
	if (iznogoud(list_a) == IZGOUD && list_a->max == list_a->tail->data)
		write(1, AR_SORT, 37);
	else if (list_a->length == 2)
		algo_2(list_a);
	else if (list_a->length == 3)
		algo_3(list_a);
	else if (list_a->length > 3 && list_a->length <= 11)
		med_algo(list_a, list_b);
	else
		big_algo_dispatch(list_a, list_b, index, stages);
	free(stages);
	stages = NULL;
}
