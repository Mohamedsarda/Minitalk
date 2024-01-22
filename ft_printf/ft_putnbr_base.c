/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:52:37 by msarda            #+#    #+#             */
/*   Updated: 2023/11/16 16:54:45 by msarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*getbase(int base, int is_m)
{
	if (base == 16 && is_m == 0)
		return ("0123456789abcdef");
	else if (base == 16 && is_m == 1)
		return ("0123456789ABCDEF");
	else if (base == 10 && is_m == 0)
		return ("0123456789");
	return (NULL);
}

int	ft_putnbr_base(long num, int base, int is_m)
{
	int		count;
	char	*base_char;

	count = 0;
	base_char = getbase(base, is_m);
	if (!base_char)
		return (0);
	if (num < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	if (num >= base)
	{
		count += ft_putnbr_base(num / base, base, is_m);
		count += ft_putchar(base_char[num % base]);
	}
	else
		count += ft_putchar(base_char[num % base]);
	return (count);
}
