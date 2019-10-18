/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:32:56 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:32:58 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar(*s);
		s++;
	}
}

int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strcat(char *s1, const char *s2)
{
	size_t i;
	size_t j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
