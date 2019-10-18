/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_begin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:33:47 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:33:48 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_output(va_list *ap, char *str, int *idx, int *len)
{
	char		*result;
	t_format	*data;

	result = NULL;
	if (!(data = initialize_format()))
		return ;
	parse_extract(str, idx, data);
	if (data->specifier == '\0')
	{
		free(data);
		return ;
	}
	result = specifier_dispatch(ap, data, result);
	if (data->specifier != 'c')
		ft_putstr(result);
	*len = *len + ft_strlen(result);
	if (result)
		free(result);
	if (data)
		free(data);
}

void	parse_extract(char *str, int *idx, t_format *data)
{
	*idx = *idx + 1;
	if (str[*idx])
	{
		if (is_flag(str[*idx]))
			set_flags(str, idx, data);
		if (is_width(str[*idx]))
			set_width(str, idx, data);
		if (is_precision(str[*idx]))
			set_precision(str, idx, data);
		else
			data->precision_reset = 1;
		if (is_length(str, *idx))
			set_length(str, idx, data);
		if (is_specifier(str[*idx]))
			set_specifier(str, idx, data);
	}
}

char	*specifier_dispatch(va_list *ap, t_format *data, char *result)
{
	if (data->specifier == 'c')
		result = manage_c(ap, data, result);
	else if (data->specifier == 's')
		result = manage_s(ap, data, result);
	else if (data->specifier == 'p')
		result = manage_p(ap, data, result);
	else if (data->specifier == 'd' || data->specifier == 'i')
		result = manage_d_i(ap, data, result);
	else if (data->specifier == 'o')
		result = manage_o(ap, data, result);
	else if (data->specifier == 'u')
		result = manage_u(ap, data, result);
	else if (data->specifier == 'x')
		result = manage_xx(ap, data, result);
	else if (data->specifier == 'X')
		result = manage_xx(ap, data, result);
	else if (data->specifier == 'f')
		result = manage_f(ap, data, result);
	else if (data->specifier == '%')
		result = manage_percent(data, result);
	else if (data->specifier == 'b')
		result = manage_b(ap, data, result);
	return (result);
}
