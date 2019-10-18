/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_specifiers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:32:45 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:32:47 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_d_i(t_format *data, char *result, int64_t nb)
{
	if ((data->flags & PLUS || data->flags & SPACE || nb < 0) &&
		(((uint64_t)nb >= (uint64_t)-9223372036854775807) ||
		(int64_t)nb >= 0))
	{
		if ((data->flags & ZERO) && data->precision == 0)
		{
			data->width -= 1;
			if (data->width > ft_strlen(result))
				result = adjust_width(data, result);
			result = adjust_plus_space(data, result, nb);
		}
		else
		{
			result = adjust_plus_space(data, result, nb);
			if (data->width > ft_strlen(result))
				result = adjust_width(data, result);
		}
	}
	else if (data->width > ft_strlen(result))
	{
		result = adjust_width(data, result);
	}
	return (result);
}

char	*handle_o(t_format *data, char *result, uint64_t nb)
{
	if (data->flags & HASH)
	{
		if (data->width >= 0 && data->precision == 0 &&
			data->precision_reset == 0)
			result = adjust_hash(data, result, nb);
		else if (data->width == 0 && data->precision > 0 &&
				(int_len_base(nb, 8) < int_len_base(nb, 10)))
			result = adjust_hash(data, result, nb);
		else if (data->width > 0 && data->precision_reset == 1)
			result = adjust_hash(data, result, nb);
		else if (data->width >= 0 && data->precision < ft_strlen(result))
			result = adjust_hash(data, result, nb);
		else if (data->precision == 0 && nb == 0 && data->precision_reset == 1)
			result = adjust_hash(data, result, nb);
		else if (data->width == 0 && data->precision > 0 && nb > 0 &&
			(int_len_base(nb, 8) != int_len_base(nb, 10)))
			result = adjust_hash(data, result, nb);
	}
	if (data->width > ft_strlen(result))
	{
		result = adjust_width(data, result);
	}
	return (result);
}

char	*handle_xx(t_format *data, char *result, uint64_t nb)
{
	if (data->flags & HASH)
	{
		if ((data->flags & ZERO) && data->precision == 0 && nb > 0)
		{
			data->width -= 2;
			if (data->width > ft_strlen(result))
				result = adjust_width(data, result);
			result = adjust_hash(data, result, nb);
		}
		else
		{
			result = adjust_hash(data, result, nb);
			if (data->width > ft_strlen(result))
				result = adjust_width(data, result);
		}
	}
	else if (data->width > ft_strlen(result))
	{
		result = adjust_width(data, result);
	}
	return (result);
}

char	*handle_f(t_format *data, char *result, double nb)
{
	if (data->flags & PLUS || data->flags & SPACE || nb < 0)
	{
		if ((data->flags & ZERO) && data->precision == 0)
		{
			data->width -= 1;
			if (data->width > ft_strlen(result))
				result = adjust_width(data, result);
			result = adjust_ps_float(data, result, nb);
		}
		else
		{
			result = adjust_ps_float(data, result, nb);
			if (data->width > ft_strlen(result))
				result = adjust_width(data, result);
		}
	}
	else if (data->width > ft_strlen(result))
	{
		result = adjust_width(data, result);
	}
	return (result);
}

char	*adjust_ps_float(t_format *data, char *result, double nb)
{
	if (data->flags & PLUS && nb >= 0)
		result = ft_stradd(result, 1, '+', 1);
	else if (nb < 0)
		result = ft_stradd(result, 1, '-', 1);
	else if (data->flags & SPACE)
		result = ft_stradd(result, 1, ' ', 1);
	return (result);
}
