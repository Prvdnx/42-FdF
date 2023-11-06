# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 19:21:14 by ookamonu          #+#    #+#              #
#    Updated: 2023/11/04 22:41:20 by ookamonu         ###   ########.fr        #
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
FLAGS = -Wall -Wextra -Werror
MLX = -L minilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): libft.a $(OUT)
	gcc $(FLAGS) -o $(NAME) $(OUT) $(MLX) ./ft_libft/libft.a

libft.a:
	$(MAKE) -C ./ft_libft
	@echo 'Compilation Complete!'

clean:
	rm -f $(OUT)
	make -C ./ft_libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./ft_libft fclean

re: fclean all
