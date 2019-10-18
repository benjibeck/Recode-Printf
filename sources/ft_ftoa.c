/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:32:10 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/14 16:20:41 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ftoa_len(double n)
{
	int		length;
	long	integer;

	integer = (long)ABS(n);
	length = 0;
	if (n < 0)
		length++;
	if (integer == 0)
		length++;
	while (integer > 0)
	{
		integer /= 10;
		length++;
	}
	return (length);
}

char	*ft_copy_dtoa(double nb, int idx, int precision)
{
	char	*str;
	long	abs_nb;

	if (!(str = malloc(sizeof(char) * idx + 1)))
		return (NULL);
	abs_nb = (long)ABS(nb);
	if (precision == 0 && (((int)(nb * 10) % 10) >= 5))
		abs_nb += 1;
	str[idx] = '\0';
	while (--idx >= 0)
	{
		str[idx] = abs_nb % 10 + '0';
		abs_nb /= 10;
	}
	if (nb < 0)
		str[++idx] = '-';
	return (str);
}

void	check_rounding(double nb, long fpart, char *str, int idx)
{
	nb = (nb - fpart) * 10;
	if (nb >= 5.0)
		str[idx - 1] = (fpart + 1) % 10 + '0';
}

char	*ft_copy_ftoa(double nb, int precision, int overflow)
{
	char	*str;
	long	fpart;
	int		idx;

	if (!(str = malloc(sizeof(char) * (precision + 2))))
		return (NULL);
	nb = ABS(nb);
	idx = 0;
	fpart = 0;
	str[idx++] = '.';
	while (precision-- > 0)
	{
		nb = (nb - fpart) * 10;
		fpart = (long)(nb);
		if (overflow > 19)
			str[idx++] = '0';
		else
			str[idx++] = fpart % 10 + '0';
		overflow++;
	}
	if (precision == -1)
		check_rounding(nb, fpart, str, idx);
	str[idx] = '\0';
	return (str);
}

char	*ft_ftoa(double n, int precision, int len, t_format *data)
{
	char	*istr;
	char	*fstr;
	char	*str;
	double	fpart;

	len = ftoa_len(n);
	if (precision > 0)
	{
		fpart = n - (long)n;
		if (!(istr = ft_copy_dtoa(n, len, data->precision)))
			return (NULL);
		if (!(fstr = ft_copy_ftoa(fpart, precision, 0)))
			return (NULL);
		str = ft_strjoin(istr, fstr);
		free(istr);
		free(fstr);
	}
	else
	{
		if (!(str = ft_copy_dtoa(n, len, data->precision)))
			return (NULL);
	}
	if (data->precision == 0 && data->flags & HASH)
		str = ft_stradd(str, 1, '.', 0);
	return (str);
}
