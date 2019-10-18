/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:32:36 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:32:38 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			idx;
	int			len;

	idx = 0;
	len = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
			format_output(&ap, (char*)str, &idx, &len);
		else
		{
			ft_putchar(str[idx++]);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
