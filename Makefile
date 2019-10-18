# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bebeck <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 21:36:33 by bebeck            #+#    #+#              #
#    Updated: 2019/10/14 16:53:50 by bebeck           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ./includes/
SRCS =	./sources/*.c
OBJS = $(SRC:.c=.o)
CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		@gcc $(CFLAGS) -I $(HEADER) -c $(SRCS)
		@ar -rc $(NAME) *.o
		@ranlib $(NAME)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
