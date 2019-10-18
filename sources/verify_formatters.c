/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_formatters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:34:10 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:34:11 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == '+' || c == '-' || c == ' ' || c == '#' || c == '0')
		return (1);
	return (0);
}

int		is_width(char c)
{
	if (c > '0' && c <= '9')
		return (1);
	return (0);
}

int		is_precision(char c)
{
	if (c == '.')
		return (1);
	return (0);
}

int		is_length(char *str, int i)
{
	if ((str[i] == 'l' && str[i + 1] != 'l') ||
		(str[i] == 'h' && str[i + 1] != 'h') ||
		(str[i] == 'l' && str[i + 1] == 'l') ||
		(str[i] == 'h' && str[i + 1] == 'h') ||
		(str[i] == 'L'))
		return (1);
	return (0);
}

int		is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o' ||
		c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%' || c == 'b')
		return (1);
	return (0);
}
