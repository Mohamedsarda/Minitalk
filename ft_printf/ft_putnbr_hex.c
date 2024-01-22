/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msarda <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:49:19 by msarda            #+#    #+#             */
/*   Updated: 2023/11/16 16:49:42 by msarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned long num, unsigned int base)
{
	int		counter;
	char	*base_char;

	counter = 0;
	base_char = "0123456789abcdef";
	if (num >= base)
	{
		counter += ft_putnbr_hex(num / base, base);
		counter += ft_putchar(base_char[num % base]);
	}
	else
		counter += ft_putchar(base_char[num % base]);
	return (counter);
}
