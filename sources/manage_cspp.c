/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cspp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:33:33 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:33:35 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_c(va_list *ap, t_format *data, char *result)
{
	int c;
	int i;

	c = va_arg(*ap, int);
	adjust_width_c(data, c);
	if (data->width == 0)
		data->width = 1;
	result = ft_strnew(data->width);
	i = 0;
	while (i < data->width)
		result[i++] = '$';
	return (result);
}

char	*manage_s(va_list *ap, t_format *data, char *result)
{
	char *str;
	char *placeholder;

	str = va_arg(*ap, char*);
	if (str)
		result = ft_strdup(str);
	else
		result = ft_strdup("(null)");
	if (data->precision_reset == 1)
		data->precision = ft_strlen(result);
	if (data->precision >= 0)
	{
		placeholder = ft_strndup(result, data->precision);
		free(result);
		result = placeholder;
	}
	if (data->width > ft_strlen(result))
		result = adjust_width(data, result);
	return (result);
}

char	*manage_p(va_list *ap, t_format *data, char *result)
{
	void *input;
	char *temp;

	input = va_arg(*ap, void*);
	temp = ft_itoa_base_upper((unsigned long long)input, 16, 0);
	result = ft_strjoin("0x", temp);
	free(temp);
	if (data->width > ft_strlen(result))
		result = adjust_width(data, result);
	return (result);
}

char	*manage_percent(t_format *data, char *result)
{
	result = ft_strdup("%");
	if (data->width > ft_strlen(result))
		result = adjust_width(data, result);
	return (result);
}
