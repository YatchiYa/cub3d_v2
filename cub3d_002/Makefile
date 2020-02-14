NAME = wolf3d

CC = gcc

FLAGS = -Wall -Wextra -Werror

FLAGS2 = -L minilibx -lmlx -framework OpenGL -framework AppKit

SRC = srcs/main.c srcs/init.c srcs/move.c srcs/update.c srcs/raycast.c srcs/init_main.c srcs/textures.c srcs/color.c

OBJS = $(SRC:.c=.o)

HEADER = srcs/wolf3d.h

all: $(NAME)

$(LIBS):
	make -C $(LIBFT_DIR)

$(NAME): $(SRC)
	$(CC) $(FLAGS) $(FLAGS2) $(SRC) -o wolf3d

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all
