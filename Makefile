# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebeck <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 21:36:33 by bebeck            #+#    #+#              #
#    Updated: 2019/10/13 21:36:36 by bebeck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
MAIN = test_main.c
HEADER = ft_printf.h
CHEADER = libftprintf.h.gch
SRCS = ft_printf.c \
malloc_functs.c \
helper_functs.c \
initialize_struct.c \
parse_begin.c \
verify_formatters.c \
set_formatters.c \
manage_cspp.c \
manage_diouxxb.c \
adjust_modifiers.c \
ft_itoa_base_upper.c \
ft_itoa.c \
length_formatters.c \
handle_specifiers.c \
ft_ftoa.c \
manage_f.c

OBJS = $(SRCS:.c=.o)
CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME): ft_printf.h
		@gcc $(CFLAGS) -c $(SRCS)
		@ar -rc $(NAME) $(OBJS)
		@ranlib $(NAME)

lib: $(HEADERS)
		@gcc $(CFLAGS) -c $(SRCS)
		@ar -rc $(NAME) $(OBJS)
		@ranlib $(NAME)

main: lib
	@gcc $(CFLAGS) $(MAIN) $(NAME) $(HEADER)
	@mv ./a.out run_test

lldb: $(SRCS) $(MAIN)
	@gcc $(CFLAGS) $(MAIN) $(NAME) $(HEADER) -g

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME) $(CHEADERS) a.out ft_printf.h.gch
	@rm -rf a.out.dSYM

re: fclean all

.PHONY: all clean fclean re
