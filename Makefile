# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romvan-d <romvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 18:23:44 by romvan-d          #+#    #+#              #
#    Updated: 2022/03/04 14:22:08 by romvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = utils_functions.c\
		ft_printf.c

OBJS = ${SRCS:.c=.o}

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

${NAME}:        ${OBJS}
		ar r $(NAME) $?

all:    ${NAME}

clean:
		${RM} ${OBJS}

fclean:         clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re