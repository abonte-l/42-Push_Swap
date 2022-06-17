/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:57:14 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 10:57:54 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	list_cleaner(t_dlst *list_a, t_dlst *list_b, t_dlst *index)
{
	dlist_delete(&index);
	dlist_delete(&list_b);
	dlist_delete(&list_a);
}

void	ft_error(t_dlst *list_a, t_dlst *list_b, t_dlst *index)
{
	list_cleaner(list_a, list_b, index);
	write(2, ERROR_TEXT, 6);
	exit(EXIT_SUCCESS);
}
