/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:20:38 by msarda            #+#    #+#             */
/*   Updated: 2023/11/01 11:29:12 by msarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check_pid(char *pid)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (*pid == '+')
		pid++;
	while (pid[i])
	{
		if (pid[i] >= '0' && pid[i] <= '9')
			j++;
		i++;
	}
	if (j == i)
		return (ft_atoi(pid));
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	long int			num;
	int					is_p;

	i = 0;
	num = 0;
	is_p = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		is_p *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * is_p);
}
