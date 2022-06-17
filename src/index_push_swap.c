/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:08:35 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:09:00 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a_index(t_dlst *list)
{
	swap(list);
}

void	swap_b_index(t_dlst *list)
{
	swap(list);
}

void	push_a_index(t_dlst *list_a, t_dlst *list_b)
{
	if (list_b == NULL)
		return ;
	push(list_b, list_a);
	list_a->length++;
	list_b->length--;
	return ;
}

void	push_b_index(t_dlst *list_a, t_dlst *list_b)
{
	if (list_a == NULL)
		return ;
	push(list_a, list_b);
	list_b->length++;
	list_a->length--;
	return ;
}
