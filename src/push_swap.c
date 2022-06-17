/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:55:30 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 11:30:45 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_dlst	*list_a;
	t_dlst	*list_b;
	t_dlst	*index;
	int		error;
	int		*pt_error;

	list_a = NULL;
	list_b = NULL;
	index = NULL;
	error = 0;
	pt_error = &error;
	if (ac == 1)
		ft_error(list_a, list_b, index);
	list_a = dlist_new(ac);
	index = dlist_new(ac);
	list_creator(av, index, list_a, pt_error);
	if (error == ERROR)
		ft_error(list_a, list_b, index);
	else
		list_b = dlist_new(ac);
	algo_launcher(list_a, list_b, index);
	dlist_delete(&index);
	dlist_delete(&list_b);
	dlist_delete(&list_a);
	return (0);
}
