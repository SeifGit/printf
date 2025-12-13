/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smellouc <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 11:36:10 by smellouc          #+#    #+#             */
/*   Updated: 2025/12/13 11:36:10 by smellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list p, char c)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar_printf(va_arg(p, int));
	else if (c == 's')
		count += ft_putstr_printf(va_arg(p, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_printf(va_arg(p, int));
	else if (c == 'u')
		count += ft_putu_printf(va_arg(p, unsigned int));
	else if (c == 'x')
		count += ft_hexa(va_arg(p, unsigned int));
	else if (c == 'X')
		count += ft_hexa_maj(va_arg(p, unsigned int));
	else if (c == 'p')
		count += ft_hexa_p(va_arg(p, void *));
	else if (c == '%')
		count += ft_putchar_printf('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				return (-1);
			count += format(ap, str[i + 1]);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
