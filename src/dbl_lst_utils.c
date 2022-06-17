/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:57:22 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 10:57:26 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlst	*dlist_new(int ac)
{
	t_dlst	*list;

	list = malloc(sizeof * list);
	if (list != NULL)
	{
		list->min = 0;
		list->max = 0;
		list->length = 0;
		list->ac_v = ac - 1;
		list->head = NULL;
		list->tail = NULL;
	}
	return (list);
}

t_dlst	*dlist_add_end(t_dlst *list, int data)
{
	t_node	*new_node;

	if (list != NULL)
	{
		new_node = malloc(sizeof * new_node);
		new_node_end(list, new_node, data);
	}
	minamax(list, data);
	return (list);
}

t_dlst	*dlist_add_start(t_dlst *list, int data)
{
	struct s_node	*new_node;

	new_node = NULL;
	if (list != NULL)
	{
		new_node = malloc(sizeof * new_node);
		new_node_start(list, new_node, data);
	}
	minamax_start(list, data);
	return (list);
}

void	check_dup(t_dlst *list, int *pt_error)
{
	struct s_node	*pos1_tmp;
	struct s_node	*pos2_tmp;

	pos1_tmp = list->head;
	pos2_tmp = NULL;
	while (pos1_tmp != NULL)
	{
		pos2_tmp = pos1_tmp->next;
		while (pos2_tmp != NULL)
		{
			if (pos1_tmp->data == pos2_tmp->data)
			{
				*pt_error = ERROR;
				return ;
			}				
			else
				pos2_tmp = pos2_tmp->next;
		}
		pos1_tmp = pos1_tmp->next;
	}
}

void	list_creator(char **av, t_dlst *index, t_dlst *list_a, int *pt_error)
{
	long long	data;
	int			i;
	int			j;	

	data = 0;
	i = list_a->ac_v;
	j = 1;
	dlist_add_start(list_a, ft_atoi(av[j], data, pt_error));
	dlist_add_start(index, ft_atoi(av[j], data, pt_error));
	i--;
	j++;
	while (i)
	{
		dlist_add_end(list_a, ft_atoi(av[j], data, pt_error));
		dlist_add_end(index, ft_atoi(av[j], data, pt_error));
		i--;
		j++;
	}
	if (list_a->length == 1)
		*pt_error = ERROR;
	check_dup(list_a, pt_error);
}
