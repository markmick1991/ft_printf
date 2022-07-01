# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psomjitr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 16:49:01 by psomjitr          #+#    #+#              #
#    Updated: 2022/03/24 13:08:39 by psomjitr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_printf.c ft_printf_csdiu.c ft_printf_px.c ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

INCLUDE	= ft_printf.h
RM	= rm -f

NAME	= libftprintf.a

all:	$(NAME)

$(NAME):$(OBJS)

$(OBJS):$(SRCS) $(INCLUDE)
	@gcc -c -Wall -Wextra -Werror $(SRCS)
	@ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
