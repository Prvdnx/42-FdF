# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 19:21:14 by ookamonu          #+#    #+#              #
#    Updated: 2023/11/10 00:55:13 by ookamonu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = src/fdf.c \
		src/read.c \
		src/for_draw.c \
		src/keys.c \
		src/draw_point.c \
		src/menu.c \
		src/need.c \
		src/read_2.c

OUT = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
MLX = -L./minilibx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OUT)
	@$(MAKE) -C ./minilibx 2>/dev/null
	$(MAKE) -C ./ft_libft
	gcc $(CFLAGS) ./ft_libft/libft.a $(OUT) -o $(NAME) $(MLX)
	@echo 'Compilation Complete!'
	
clean:
	rm -f $(OUT)
	make -C ./ft_libft clean
	$(MAKE) -C ./minilibx clean

fclean: clean
	make -C ./ft_libft fclean
	$(MAKE) -C ./minilibx clean

re: fclean all
