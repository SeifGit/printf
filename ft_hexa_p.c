/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smellouc <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 11:36:17 by smellouc          #+#    #+#             */
/*   Updated: 2025/12/13 11:36:17 by smellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hexacount(unsigned long nb)
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

static void	recur_p(unsigned long h)
{
	char	*hexad;

	hexad = "0123456789abcdef";
	if (h / 16 != 0)
		recur_p(h / 16);
	ft_putchar_printf(hexad[h % 16]);
}

int	ft_hexa_p(void *h)
{
	unsigned long	j;

	j = (unsigned long)h;
	if (h == NULL)
	{
		ft_putstr_printf("(nil)");
		return (5);
	}
	ft_putstr_printf("0x");
	recur_p(j);
	return (hexacount(j) + 2);
}

/*int main(void)
{
	char c = 'a';
	int i = ft_hexa_p(&c);

	printf("\n %d", i);
}*/