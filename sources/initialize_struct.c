/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:33:07 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:33:09 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*initialize_format(void)
{
	t_format *data;

	if (!(data = malloc(sizeof(data))))
		return (NULL);
	data->specifier = '\0';
	data->length = 0;
	data->flags = 0;
	data->precision = 0;
	data->precision_reset = 0;
	data->width = 0;
	return (data);
}
