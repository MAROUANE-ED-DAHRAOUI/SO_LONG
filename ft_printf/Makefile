# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: med-dahr <med-dahr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:06:35 by med-dahr          #+#    #+#              #
#    Updated: 2024/01/16 14:57:13 by med-dahr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_putchar.c ft_putstr.c \
	 ft_format_hexa.c \
	 ft_lower_hexa.c \
	 ft_upper_hexa.c \
	 ft_put_unsigned.c \
	 ft_putnbr.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = ${SRC:.c=.o}
NAME = libftprintf.a
HEADER = ft_printf.h
all: ${NAME}

${NAME}: ${OBJ} ${HEADER}
	ar -rcs ${NAME} ${OBJ}

%.o:%.c
	${CC} ${FLAGS} -c $< -o $@

clean:
		rm -rf ${OBJ}

fclean: clean
		rm -fr ${NAME}

re: fclean all

.PHONY : clean
