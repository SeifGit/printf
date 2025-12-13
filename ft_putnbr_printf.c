/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smellouc <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:04:07 by smellouc          #+#    #+#             */
/*   Updated: 2025/12/13 18:54:08 by smellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countnb(int nb)
{
	int	count;

	count = 0;
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	count += 1;
	return (count);
}

int	ft_putnbr_printf(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		count += ft_putchar_printf('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr_printf(n / 10);
	ft_putchar_printf(n % 10 + 48);
	count += countnb(n);
	return (count);
}

/*int	main(void)
{
	int i = ft_putnbr_printf(-2147483648);

	printf("\n%d", i);
}*/