/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smellouc <marvin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 17:20:38 by smellouc          #+#    #+#             */
/*   Updated: 2025/12/08 17:20:38 by smellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_putstr_printf(char *s);
int	ft_putchar_printf(char c);
int	ft_putnbr_printf(int n);
int	ft_putu_printf(unsigned int n);
int	ft_hexa(unsigned int h);
int	ft_hexa_maj(unsigned int h);
int	ft_hexa_p(void *h);

#endif