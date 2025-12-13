/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smellouc <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 18:04:07 by smellouc          #+#    #+#             */
/*   Updated: 2025/12/13 16:24:23 by smellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	countnb(unsigned int nb)
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

int	ft_putu_printf(unsigned int n)
{
	unsigned int	count;

	count = 0;
	if (n > 9)
		ft_putu_printf(n / 10);
	ft_putchar_printf(n % 10 + 48);
	count += countnb(n);
	return (count);
}

/*int	main(void)
{
	int i;
	
	i =ft_putu_printf(42);
	printf("\n%d", i);
}*/