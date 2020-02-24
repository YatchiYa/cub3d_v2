NAME = cub3d

CC = gcc

FLAGS = -Wall -Wextra -Werror

FLAGS2 = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRC = srcs/main.c srcs/init.c srcs/move.c srcs/update.c srcs/raycast.c srcs/init_main.c srcs/textures.c srcs/color.c \
		srcs/sprite.c srcs/move_2.c srcs/bitmap.c srcs/ft_memcpy.c srcs/put_pxl_to_img.c srcs/wall.c \
		srcs/map_config.c srcs/hooks.c

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
