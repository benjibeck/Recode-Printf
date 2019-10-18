/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_formatters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:33:18 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/14 16:20:59 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		length_d_i(va_list *ap, t_format *data)
{
	int64_t		temp;

	if (data->length & LOWER_L)
		temp = va_arg(*ap, long int);
	else if (data->length & LOWER_H)
		temp = (short)va_arg(*ap, int);
	else if (data->length & LOWER_LL)
		temp = va_arg(*ap, int64_t);
	else if (data->length & LOWER_HH)
		temp = (signed char)va_arg(*ap, int);
	else
		temp = va_arg(*ap, int);
	return (temp);
}

uint64_t	length_ouxxb(va_list *ap, t_format *data)
{
	uint64_t	temp;

	if (data->length & LOWER_L)
		temp = va_arg(*ap, unsigned long int);
	else if (data->length & LOWER_H)
		temp = va_arg(*ap, unsigned int);
	else if (data->length & LOWER_LL)
		temp = va_arg(*ap, uint64_t);
	else if (data->length & LOWER_HH)
		temp = va_arg(*ap, unsigned int);
	else
		temp = va_arg(*ap, unsigned int);
	return (temp);
}

double		length_f(va_list *ap, t_format *data)
{
	double	temp;

	if (data->length & LOWER_L)
		temp = va_arg(*ap, double);
	else if (data->length & UPPER_L)
		temp = va_arg(*ap, long double);
	else
		temp = va_arg(*ap, double);
	return (temp);
}
