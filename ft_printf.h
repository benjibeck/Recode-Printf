/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bebeck <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 21:37:16 by bebeck            #+#    #+#             */
/*   Updated: 2019/10/13 21:37:17 by bebeck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <string.h>

# define ABS(N) ((N < 0) ? (-N) : (N))

# define LOWER_L 1
# define LOWER_H 2
# define LOWER_LL 4
# define LOWER_HH 8
# define UPPER_L 16

# define PLUS 1
# define MINUS 2
# define SPACE 4
# define ZERO 8
# define HASH 16

typedef	struct	s_format
{
	char			specifier;
	unsigned int	length : 5;
	unsigned int	flags : 5;
	int				precision;
	int				precision_reset;
	int				width;
}				t_format;

int				ft_printf(const char *str, ...);
t_format		*initialize_format(void);
void			parse_extract(char *str, int *idx, t_format *data);
void			format_output(va_list *ap, char *str, int *idx, int *len);
char			*specifier_dispatch(va_list *ap, t_format *data, char *result);

int				is_flag(char c);
int				is_width(char c);
int				is_precision(char c);
int				is_length(char *str, int i);
int				is_specifier(char c);

void			set_flags(char *str, int *idx, t_format *data);
void			set_width(char *str, int *idx, t_format *data);
void			set_precision(char *str, int *idx, t_format *data);
void			set_length(char *str, int *idx, t_format *data);
void			set_specifier(char *str, int *idx, t_format *data);

char			*manage_c(va_list *ap, t_format *data, char *result);
char			*manage_s(va_list *ap, t_format *data, char *result);
char			*manage_p(va_list *ap, t_format *data, char *result);
char			*manage_d_i(va_list *ap, t_format *data, char *result);
char			*manage_o(va_list *ap, t_format *data, char *result);
char			*manage_u(va_list *ap, t_format *data, char *result);
char			*manage_xx(va_list *ap, t_format *data, char *result);
char			*manage_f(va_list *ap, t_format *data, char *result);
char			*manage_percent(t_format *data, char *result);
char			*manage_b(va_list *ap, t_format *data, char *result);

int64_t			length_d_i(va_list *ap, t_format *data);
uint64_t		length_ouxxb(va_list *ap, t_format *data);
double			length_f(va_list *ap, t_format *data);

char			*handle_d_i(t_format *data, char *result, int64_t nb);
char			*handle_o(t_format *data, char *result, uint64_t nb);
char			*handle_xx(t_format *data, char *result, uint64_t nb);
char			*handle_f(t_format *data, char *result, double nb);

char			*adjust_width(t_format *data, char *result);
char			*adjust_precision(int len, char *result);
char			*adjust_plus_space(t_format *data, char *result, int64_t nb);
char			*adjust_ps_float(t_format *data, char *result, double nb);
char			*adjust_hash(t_format *data, char *result, uint64_t nb);
void			adjust_width_c(t_format *data, int c);

int				int_len(int64_t nbr);
int				int_len_base(uint64_t nbr, int base);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
int				ft_strlen(const char *s);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strdup(const char *s1);
char			*ft_strnew(size_t size);
char			*ft_strndup(const char *s1, int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_stradd(char *src, int len, char c, int front);
char			*ft_ftoa(double n, int precision, int len, t_format *data);
char			*ft_itoa(int64_t nbr);
char			*ft_itoa_base_upper(uint64_t nbr, int base, int uppercase);

#endif
