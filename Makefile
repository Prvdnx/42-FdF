# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 19:21:14 by ookamonu          #+#    #+#              #
#    Updated: 2023/11/08 01:15:59 by ookamonu         ###   ########.fr        #
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
MLX_DIR = ./minilibx
MLX = -L./minilibx -lmlx -framework OpenGL -framework AppKit
HEADER = fdf.h

all: $(NAME)

$(NAME): $(OUT)
	@$(MAKE) -C ./minilibx
	$(MAKE) -C ./ft_libft
	gcc -o $(NAME) $(OUT) $(MLX) ./ft_libft/libft.a
	@echo 'Compilation Complete!'

%.o: %.c $(HEADER)
	@gcc -Wall -Wextra -Werror -I. -c $< -o $@
	
clean:
	rm -f $(OUT)
	make -C ./ft_libft clean

fclean: clean
	make -C ./ft_libft fclean

re: fclean all
