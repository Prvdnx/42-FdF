# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ookamonu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 06:17:43 by ookamonu          #+#    #+#              #
#    Updated: 2023/11/11 06:26:47 by ookamonu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_strdup.c \
	  ft_strsub.c \
	  ft_strnew.c \
	  ft_strjoin.c \
	  ft_strlcpy.c \
	  ft_split.c \
	  ft_atoi.c \
	  ft_isspace.c \
	  ft_tolower.c \
	  ft_putchar.c \
	  ft_putstr.c \
	  ft_putendl.c \
	  ft_strndup.c \
	  ft_strlen.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  get_next_line.c \
	  ft_word_count.c \
	  ft_abs.c

OBJ = $(SRC:.c=.o)

INCLUDES=./

all: $(NAME) 

$(NAME):
	gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
