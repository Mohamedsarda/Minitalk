/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:55:11 by msarda            #+#    #+#             */
/*   Updated: 2023/11/16 16:55:41 by msarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		counter;

	if (write(1, "", 0) < 0)
		return (-1);
	counter = 0;
	if (!str)
		return (0);
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			counter += ft_action(*(++str), ap);
		else
			counter += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (counter);
}
