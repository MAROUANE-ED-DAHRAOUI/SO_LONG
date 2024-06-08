# Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
NAME = so_long
SRCDIR = src_file
UTILS = utils_files

SRC = so_long.c init_info.c  check_map.c chk_fileName.c  flood_fill.c init_game.c check_keys.c # Add all your source files here
SRCU = ft_split.c ft_strdup.c ft_strlcpy.c
SRC := $(addprefix $(SRCDIR)/, $(SRC))
SRCU := $(addprefix $(UTILS)/, $(SRCU))
OBJ = $(SRC:.c=.o)
OBJU = $(SRCU:.c=.o)
INCLUDES = -I include
MLX = ../minilibx/libmlx.a

# Rules

%.o: %.c ../include/so_long.h
	$(CC) $(CFLAGS) -Imlx_linux -O3 -c $<  $(INCLUDES) -o $@

all: $(NAME)

$(NAME): $(OBJ) $(OBJU)
	make -C ft_printf
	make -C get_next_line
	$(CC) $(CFLAGS) $^ get_next_line/get_next_line.a ft_printf/libftprintf.a -framework OpenGL -framework AppKit $(INCLUDES) $(MLX) -o $(NAME)

clean:
	make -C ft_printf clean
	make -C get_next_line clean
	$(RM) $(OBJ) $(OBJU)

fclean: clean
	make -C ft_printf fclean
	make -C get_next_line fclean
	$(RM) $(NAME) $(OBJ) $(OBJU)

re: fclean all