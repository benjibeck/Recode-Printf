/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_formatters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:33:53 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/14 16:28:43 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flags(char *str, int *idx, t_format *data)
{
	while (str[*idx] && is_flag(str[*idx]))
	{
		if (str[*idx] == '+')
			data->flags |= PLUS;
		else if (str[*idx] == '-')
			data->flags |= MINUS;
		else if (str[*idx] == ' ')
			data->flags |= SPACE;
		else if (str[*idx] == '0')
			data->flags |= ZERO;
		else if (str[*idx] == '#')
			data->flags |= HASH;
		*idx = *idx + 1;
	}
}

void	set_width(char *str, int *idx, t_format *data)
{
	while (str[*idx] >= '0' && str[*idx] <= '9')
	{
		data->width = (data->width * 10) + str[*idx] - '0';
		*idx = *idx + 1;
	}
}

void	set_precision(char *str, int *idx, t_format *data)
{
	*idx = *idx + 1;
	while (str[*idx] >= '0' && str[*idx] <= '9')
	{
		data->precision = (data->precision * 10) + str[*idx] - '0';
		*idx = *idx + 1;
	}
}

void	set_length(char *str, int *idx, t_format *data)
{
	if (str[*idx] == 'l' && str[*idx + 1] != 'l')
	{
		data->length |= LOWER_L;
		*idx = *idx + 1;
	}
	else if (str[*idx] == 'L')
	{
		data->length |= UPPER_L;
		*idx = *idx + 1;
	}
	else if (str[*idx] == 'h' && str[*idx + 1] != 'h')
	{
		data->length |= LOWER_H;
		*idx = *idx + 1;
	}
	else if (str[*idx] == 'l' && str[*idx + 1] == 'l')
	{
		data->length |= LOWER_LL;
		*idx = *idx + 2;
	}
	else if (str[*idx] == 'h' && str[*idx + 1] == 'h')
	{
		data->length |= LOWER_HH;
		*idx = *idx + 2;
	}
}

void	set_specifier(char *str, int *idx, t_format *data)
{
	if (str[*idx] == 'c')
		data->specifier = str[*idx];
	else if (str[*idx] == 's')
		data->specifier = str[*idx];
	else if (str[*idx] == 'p')
		data->specifier = str[*idx];
	else if (str[*idx] == 'd' || str[*idx] == 'i')
		data->specifier = str[*idx];
	else if (str[*idx] == 'o')
		data->specifier = str[*idx];
	else if (str[*idx] == 'u')
		data->specifier = str[*idx];
	else if (str[*idx] == 'x')
		data->specifier = str[*idx];
	else if (str[*idx] == 'X')
		data->specifier = str[*idx];
	else if (str[*idx] == 'f')
		data->specifier = str[*idx];
	else if (str[*idx] == '%')
		data->specifier = str[*idx];
	else if (str[*idx] == 'b')
		data->specifier = str[*idx];
	*idx = *idx + 1;
}
