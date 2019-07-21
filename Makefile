# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/11 16:02:55 by ykliek            #+#    #+#              #
#    Updated: 2019/05/11 16:03:04 by ykliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Werror -Wextra

FRAMEWORKS = -framework OpenGL -framework AppKit -O2

LIB = libft/libft.a

MLX = minilibx_macos/libmlx.a

SRCS = src/main.c \
		src/fdf.c \
		src/lst_tools.c \
		src/parse_map.c \
		src/ft_atoi_base.c \
		src/functionality.c \
		src/key_bindings.c \
		src/draw_figure.c \
		src/tools.c \
		src/validator.c

INCLUDE = ./includes/fdf.h

all: $(NAME)

$(NAME):
	@make -C libft
	@make -C minilibx_macos
	gcc $(FLAGS) $(FRAMEWORKS) $(SRCS) $(MLX) $(LIB) -I $(INCLUDE) -o $(NAME) 

clean:
	@rm -rf $(OBJ)
	@make -C libft clean 
	@make -C minilibx_macos clean
	@rm -f fdf.h.gch

fclean: clean
	@rm -f $(NAME)
	@make -C minilibx_macos fclean
	@make -C libft fclean

re: fclean all

cleanlib:
	make -C libft clean

fcleanlib:
	make -C libft fclean

relib:
	make -C libft re

cleanmlx:
	make -C minilibx_macos clean

fcleanmlx:
	make -C minilibx_macos clean

remlx:
	make -C minilibx_macos re

noflags:
	gcc $(FRAMEWORKS) $(SRCS) $(MLX) $(LIB) -I $(INCLUDE) -o $(NAME) 
