/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smellouc <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 11:36:24 by smellouc          #+#    #+#             */
/*   Updated: 2025/12/13 11:36:24 by smellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexacount(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb / 16 != 0)
	{
		nb /= 16;
		count++;
	}
	return (count + 1);
}

int	ft_hexa(unsigned int h)
{
	char	*hexad;

	hexad = "0123456789abcdef";
	if (h == 0)
	{
		ft_putchar_printf('0');
		return (1);
	}
	if (h / 16 != 0)
		ft_hexa(h / 16);
	ft_putchar_printf(hexad[h % 16]);
	return (hexacount(h));
}

/*int main(void)
{
	int i = ft_hexa(11144885);
	printf("\n %d", i);
}*/