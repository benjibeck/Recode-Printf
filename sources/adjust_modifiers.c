/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_modifiers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:31:59 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/14 16:08:02 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*adjust_width(t_format *data, char *result)
{
	int add_len;

	add_len = (int)data->width - ft_strlen(result);
	if (data->flags & MINUS)
		result = ft_stradd(result, add_len, ' ', 0);
	else if ((data->flags & ZERO) && data->precision == 0)
		result = ft_stradd(result, add_len, '0', 1);
	else
		result = ft_stradd(result, add_len, ' ', 1);
	return (result);
}

void	adjust_width_c(t_format *data, int c)
{
	int add_len;

	add_len = (int)data->width - 1;
	if (data->flags & MINUS)
	{
		ft_putchar((char)c);
		while (add_len--)
			ft_putchar(' ');
	}
	else if (data->width > 0)
	{
		while (add_len--)
			ft_putchar(' ');
		ft_putchar((char)c);
	}
	else
		ft_putchar((char)c);
	return ;
}

char	*adjust_precision(int len, char *result)
{
	result = ft_stradd(result, len, '0', 1);
	return (result);
}

char	*adjust_plus_space(t_format *data, char *result, int64_t nb)
{
	if (data->flags & PLUS && nb >= 0)
		result = ft_stradd(result, 1, '+', 1);
	else if ((data->flags & PLUS) && nb < 0)
		result = ft_stradd(result, 1, '-', 1);
	else if ((data->specifier == 'd' || data->specifier == 'i') && nb < 0)
		result = ft_stradd(result, 1, '-', 1);
	else if (data->flags & SPACE)
		result = ft_stradd(result, 1, ' ', 1);
	return (result);
}

char	*adjust_hash(t_format *data, char *result, uint64_t nb)
{
	char *placeholder;

	if ((data->flags & HASH) && data->specifier == 'o' &&
		(!(nb == 0 && data->precision_reset == 1)))
	{
		placeholder = ft_strjoin("0", result);
		free(result);
		result = placeholder;
	}
	else if ((data->flags & HASH) && data->specifier == 'x' && nb > 0)
	{
		placeholder = ft_strjoin("0x", result);
		free(result);
		result = placeholder;
	}
	else if ((data->flags & HASH) && data->specifier == 'X' && nb > 0)
	{
		placeholder = ft_strjoin("0X", result);
		free(result);
		result = placeholder;
	}
	return (result);
}
