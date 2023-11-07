# Compiler and linker settings
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

# Project settings
NAME = fdf
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = ft_libft
MLX_DIR = minilibx

# Source files
SRC_FILES = fdf.c \
			read.c \
			for_draw.c \
			keys.c \
			draw_point.c \
			menu.c \
			need.c \
			read_2.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Targets
.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@make -C $(MLX_DIR) --silent
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJ) $(LIBFT)
	@echo 'Compilation Complete!'

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(OBJ)

re: fclean all
