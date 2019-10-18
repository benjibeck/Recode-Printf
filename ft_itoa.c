/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:32:18 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:32:20 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		absolute(int64_t nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

int		int_len(int64_t nbr)
{
	int		len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char	*ft_itoa(int64_t nbr)
{
	char	*str;
	int		len;

	len = int_len(nbr);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	if (nbr < 0)
		str[0] = '-';
	else if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[--len] = absolute(nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
