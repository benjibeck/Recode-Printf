/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_diouxx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:33:41 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/14 16:23:07 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_d_i(va_list *ap, t_format *data, char *result)
{
	int64_t temp;

	temp = length_d_i(ap, data);
	if (data->precision_reset == 0 && data->precision == 0 && temp == 0)
		result = ft_strdup("");
	else
		result = ft_itoa((ABS(temp)));
	if (data->precision > ft_strlen(result))
		result =
			adjust_precision((data->precision - ft_strlen(result)), result);
	result = handle_d_i(data, result, temp);
	return (result);
}

char	*manage_o(va_list *ap, t_format *data, char *result)
{
	uint64_t temp;

	temp = length_ouxxb(ap, data);
	if (data->precision_reset == 0 && data->precision == 0 && temp == 0)
		result = ft_strdup("");
	else
		result = ft_itoa_base_upper(temp, 8, 0);
	if (data->precision > ft_strlen(result))
		result =
			adjust_precision((data->precision - ft_strlen(result)), result);
	result = handle_o(data, result, temp);
	return (result);
}

char	*manage_u(va_list *ap, t_format *data, char *result)
{
	uint64_t temp;

	temp = length_ouxxb(ap, data);
	if (data->precision_reset == 0 && data->precision == 0 && temp == 0)
		result = ft_strdup("");
	else
		result = ft_itoa_base_upper(temp, 10, 0);
	if (data->precision > ft_strlen(result))
		result =
			adjust_precision((data->precision - ft_strlen(result)), result);
	if (data->width > ft_strlen(result))
		result = adjust_width(data, result);
	return (result);
}

char	*manage_xx(va_list *ap, t_format *data, char *result)
{
	uint64_t temp;

	temp = length_ouxxb(ap, data);
	if (data->precision_reset == 0 && data->precision == 0 && temp == 0)
		result = ft_strdup("");
	else if (data->specifier == 'x')
		result = ft_itoa_base_upper(temp, 16, 0);
	else if (data->specifier == 'X')
		result = ft_itoa_base_upper(temp, 16, 1);
	if (data->precision > ft_strlen(result))
		result =
			adjust_precision((data->precision - ft_strlen(result)), result);
	result = handle_xx(data, result, temp);
	return (result);
}

char	*manage_b(va_list *ap, t_format *data, char *result)
{
	uint64_t temp;

	temp = length_ouxxb(ap, data);
	if (data->precision_reset == 0 && data->precision == 0 && temp == 0)
		result = ft_strdup("");
	else
		result = ft_itoa_base_upper(temp, 2, 0);
	if (data->precision > ft_strlen(result))
		result =
			adjust_precision((data->precision - ft_strlen(result)), result);
	if (data->width > ft_strlen(result))
		result = adjust_width(data, result);
	return (result);
}
