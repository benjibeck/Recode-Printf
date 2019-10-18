/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:32:27 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:32:29 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_len_base(uint64_t nbr, int base)
{
	int		len;

	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr /= base;
	}
	return (len);
}

int		is_value(uint64_t nbr, int uppercase)
{
	if (nbr <= 9)
		return (48);
	else if (nbr >= 10 && nbr <= 15)
	{
		if (uppercase)
			return (65 - 10);
		else
			return (97 - 10);
	}
	return (0);
}

char	*ft_itoa_base_upper(uint64_t nbr, int base, int uppercase)
{
	char	*str;
	int		len;

	len = int_len_base(nbr, base);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = nbr % base + is_value((nbr % base), uppercase);
		nbr /= base;
	}
	return (str);
}
