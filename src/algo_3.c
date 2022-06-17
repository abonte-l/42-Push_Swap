/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 10:29:46 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/15 23:04:45 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_3(t_dlst *list)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = list->head->data;
	v2 = list->head->next->data;
	v3 = list->tail->data;
	if (v1 > v2 && v1 > v3)
		rotate_a(list);
	else if (v2 > v1 && v2 > v3)
		rev_rotate_a(list);
	else if (v1 > v2)
		swap_a(list);
	else
		return ;
	algo_3(list);
	return ;
}
