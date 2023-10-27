
NAME = fdf
SRC = src/fdf.c \
		src/read.c \
		src/for_draw.c \
		src/keys.c \
		src/test_draw_point.c \
		src/menu.c \
		src/need.c \
		src/read_2.c
OUT = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OUT)
	make -C ./libft
	gcc $(FLAGS) -o $(NAME) $(OUT) $(MLX) ./libft/libft.a
	@echo 'Compiled!'

clean:
	rm -f $(OUT)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all
