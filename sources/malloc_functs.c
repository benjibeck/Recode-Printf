/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:33:26 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:33:28 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		str[size] = '\0';
	}
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	idx;

	len = 0;
	while (s1[len])
		len++;
	if (!(dup = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		dup[idx] = s1[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}

char	*ft_strndup(const char *s1, int len)
{
	char	*dup;
	size_t	idx;

	if (!(dup = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	idx = 0;
	while (s1[idx] && len--)
	{
		dup[idx] = s1[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		join_len;

	if (!s1 || !s2)
		return (0);
	join_len = (ft_strlen(s1) + ft_strlen(s2));
	if (!(new_str = ft_strnew(join_len)))
		return (NULL);
	new_str = ft_strcat(new_str, s1);
	new_str = ft_strcat(new_str, s2);
	return (new_str);
}

char	*ft_stradd(char *src, int len, char c, int front)
{
	char	*temp;
	char	*result;

	if (!len || !src)
		return (src);
	if (!(temp = ft_strnew(len)))
		return (src);
	while (len)
		temp[--len] = c;
	if (front)
		result = ft_strjoin(temp, src);
	else
		result = ft_strjoin(src, temp);
	free(src);
	free(temp);
	return (result);
}
