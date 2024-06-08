# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: med-dahr <med-dahr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 11:06:35 by med-dahr          #+#    #+#              #
#    Updated: 2024/06/08 22:17:26 by med-dahr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c get_next_line_utils.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = ${SRC:.c=.o}
NAME = get_next_line.a
HEADER = get_next_line.h
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