/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:56:54 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 15:29:06 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define SUCCESS 0
# define ERROR -1
# define ERROR_TEXT	"Error\n"

# define INT_MAX 2147483647
# define INT_MIN -2147483647
# define INT_ERROR 2147483648

# define PUSH_A "pa\n"
# define PUSH_B "pb\n"
# define SWAP_A "sa\n"
# define SWAP_B "sb\n"
# define DOUBLE_SWAP "ss\n"
# define ROTATE_A "ra\n"
# define ROTATE_B "rb\n"
# define DOUBLE_ROTATE "rr\n"
# define REV_ROTATE_A "rra\n"
# define REV_ROTATE_B "rrb\n"
# define DOUBLE_REV_ROTATE "rrr\n"

# define IZNOGOUD -1
# define IZGOUD 0

# define TRUE 1
# define FALSE 0

# define REV_ROTATE 1
# define ROTATE 0

# define AR_SORT "Already sorted, no operations needed\n"

/*
** defining node of the linked list
*/
typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

/*
** defining a double linked list
*/
typedef struct s_dlst
{
	int				min;
	int				max;
	int				length;
	int				len_tmp;
	int				ac_v;
	int				pos_push;
	struct s_node	*tail;
	struct s_node	*head;
}					t_dlst;

/* ************************************** */

typedef struct s_stages
{
	int		nb_pile;
	int		current_pile;
	int		counter_stage_tmp;
	int		current_stage;
	int		pos_head;
	int		pos_tail;
	int		counter_stage;
	int		list_len;
}					t_stages;

typedef struct s_piles
{
	int		top_num;
	int		top_min;
	int		top_max;
	int		low_num;
	int		low_min;
	int		low_max;
}					t_piles;

/*
** min/max functions
*/
void	minamax_start(t_dlst *list, int data);
void	minamax(t_dlst *list, int data);
void	find_minamax(t_dlst *list_a, t_dlst *list_b);
int		find_min(t_dlst *list_a, int pos_min);
int		find_pospush(t_dlst *list_a, t_dlst *list_b, int pos_push);
int		find_pospush_index(t_dlst *index, t_dlst *list_b);
void	init_minamax(t_dlst *list);

/*
** error function
*/
void	ft_error(t_dlst *list_a, t_dlst *list_b, t_dlst *index);

/*
** double linked list functions
*/
t_dlst	*empty_list_creator(t_dlst *list_b);
void	dlist_delete(t_dlst **list);
t_dlst	*dlist_new(int ac);
t_dlst	*dlist_add_end(t_dlst *list, int data);
t_dlst	*dlist_add_start(t_dlst *list, int data);
void	new_node_end(t_dlst *list, t_node *new_node, int data);
void	new_node_start(t_dlst *list, t_node *new_node, int data);
void	list_generator(t_dlst *index, t_dlst *list_a, t_dlst *list_b);
void	list_creator(char **av, t_dlst *index, t_dlst *list_a, int *pt_error);

/*
** converting functions (ASCII + int)
*/
int		ft_atoi(char *str, long long num, int *error);
int		verif_error(char *str);

/*
** dispatch according to the number of figures to sort 
** and to the number of piles
*/
void	algo_launcher(t_dlst *list_a, t_dlst *list_b, t_dlst *index);
void	big_fig_launcher(t_dlst *list_a, t_dlst *list_b, t_dlst *index,
			t_stages *stages);

/*
** swap functions
*/
void	swap(t_dlst *list);
void	swap_b(t_dlst *list);
void	swap_a(t_dlst *list);
void	double_swap(t_dlst *list_a, t_dlst *list_b);
void	opti_swap(t_dlst *list_a, t_dlst *list_b);
void	swap_a_index(t_dlst *list);
void	swap_b_index(t_dlst *list);

/*
** rotate functions
*/
void	rotate(t_dlst *list);
void	rotate_a(t_dlst *list);
void	rotate_b(t_dlst *list);
void	rotate_a_index(t_dlst *list);
void	rotate_b_index(t_dlst *list);
void	double_rotate(t_dlst *list_a, t_dlst *list_b);

/*
** reverse rotate functions
*/
void	rev_rotate(t_dlst *list);
void	rev_rotate_a(t_dlst *list);
void	rev_rotate_b(t_dlst *list);
void	rev_rotate_a_index(t_dlst *list);
void	rev_rotate_b_index(t_dlst *list);
void	double_rev_rotate(t_dlst *list_a, t_dlst *list_b);

/*
** push functions
*/
void	push(t_dlst *list_1, t_dlst *list_2);
void	push_a(t_dlst *list_a, t_dlst *list_b);
void	push_b(t_dlst *list_a, t_dlst *list_b);
void	push_a_index(t_dlst *list_a, t_dlst *list_b);
void	push_b_index(t_dlst *list_a, t_dlst *list_b);

/*
** algo_2 function
*/
void	algo_2(t_dlst *list);

/*
** algo_3 function
*/
void	algo_3(t_dlst *list);

/*
** algo_5 functions
*/
void	med_algo(t_dlst *list_a, t_dlst *list_b);
int		iznogoud(t_dlst *list);
void	init_minamax(t_dlst *list);
int		find_pospush(t_dlst *list_a, t_dlst *list_b, int pos_push);

/*
** algo big figures functions
*/
int		find_in_a(t_dlst *list, t_stages *stages, t_piles *pile);
void	big_algo(t_dlst *list_a, t_dlst *list_b, t_stages *stages);

/*
** indexation functions
*/
void	init_index(t_dlst *list_b, t_dlst *index);
void	put_index_a(t_dlst *list_a, t_dlst *index);
void	med_algo_index(t_dlst *index, t_dlst *list_b);

/*
** init structures functions
*/
void	init_stages(t_stages *stages, t_dlst *list);
void	re_init_stages(t_stages *stages);
void	init_minamax(t_dlst *list);

#endif
