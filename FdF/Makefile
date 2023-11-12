# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 19:21:14 by ookamonu          #+#    #+#              #
#    Updated: 2023/11/13 02:33:57 by ookamonu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC =	src/fdf.c \
		src/reading.c \
		src/bresenham.c \
		src/drawing.c \
		src/colorNmenu.c \
		src/do_isometric.c

OUT = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
MLX = -L./minilibx_macos -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OUT)
	@$(MAKE) -C ./minilibx_macos 2>/dev/null
	$(MAKE) -C ./ft_libft
	gcc $(CFLAGS) -o $(NAME) $(OUT) ./ft_libft/libft.a $(MLX)
	@echo 'Compilation Complete!'
	
clean:
	rm -f $(OUT)
	make -C ./ft_libft clean
	$(MAKE) -C ./minilibx_macos clean

fclean: clean
	rm -f $(NAME)
	make -C ./ft_libft fclean
	$(MAKE) -C ./minilibx_macos clean

re: fclean all
