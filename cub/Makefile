NAME = cub3d

CC = gcc

FLAGS = -Wall -Wextra -Werror

FLAGS2 = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRC = srcs/main.c srcs/init.c srcs/move.c srcs/update.c srcs/raycast.c srcs/init_main.c srcs/textures.c srcs/color.c \
		srcs/sprite.c srcs/move_2.c srcs/bitmap.c srcs/ft_memcpy.c srcs/put_pxl_to_img.c srcs/wall.c \
		srcs/map_config.c srcs/hooks.c srcs/ft_strcmp.c \
		srcs/ft_atoi.c srcs/ft_endwith.c srcs/ft_in_set.c srcs/str.c \
		srcs/ft_split.c srcs/parse_map_config.c srcs/parse_elem.c srcs/ft_memmove.c srcs/ft_strdup.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c srcs/parse_map.c srcs/close.c \
		srcs/parse_2.c

OBJS = $(SRC:.c=.o)

HEADER = srcs/wolf3d.h

all: $(NAME)

$(LIBS):
	make -C $(LIBFT_DIR)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(FLAGS2) $(SRC) -o cub3d

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
