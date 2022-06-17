/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonte-l <abonte-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:55:02 by abonte-l          #+#    #+#             */
/*   Updated: 2021/12/17 15:48:46 by abonte-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_ascii(char *str, int *pt_error)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && !(str[i] == '-')
			&& !(str[i] == '+'))
			*pt_error = ERROR;
		i++;
	}
}

int	check_whitespace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		++i;
	return (i);
}

int	ft_atoi(char *str, long long num, int *pt_error)
{
	int	i;
	int	neg;

	i = 0;
	neg = 1;
	check_ascii(str, pt_error);
	check_whitespace(str, i);
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		++i;
	}
	num = num * neg;
	if (num > INT_MAX || num < INT_MIN)
		*pt_error = ERROR;
	return (num);
}
