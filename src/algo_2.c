/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:50:46 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 10:41:01 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_2(t_dlst *list)
{
	if (iznogoud(list) == IZNOGOUD || (iznogoud(list) == IZGOUD
			&& list->max != list->tail->data))
		rotate_a(list);
	else
		write(1, AR_SORT, 37);
}
