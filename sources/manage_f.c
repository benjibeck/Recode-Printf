/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:20 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/14 16:24:28 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_f(va_list *ap, t_format *data, char *result)
{
	double temp;

	temp = length_f(ap, data);
	if (data->precision_reset == 1)
		data->precision = 6;
	result = ft_ftoa((ABS(temp)), data->precision, 0, data);
	result = handle_f(data, result, temp);
	return (result);
}
