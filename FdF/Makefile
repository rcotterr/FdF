# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 18:33:13 by mmcclure          #+#    #+#              #
#    Updated: 2019/03/12 14:33:31 by mmcclure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

MINILIB = minilibx_macos/libmlx.a

LIB = libft/libft.a

SRCS = ./srcs/main.c ./srcs/read.c ./srcs/valid.c ./srcs/make_arr.c ./srcs/window.c \
		./srcs/image.c ./srcs/hook.c\
			./libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

rr:
	rm -f $(NAME)
	gcc $(FLAGS) $(SRCS) -I ./minilibx_macos -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME) -ggdb

$(NAME): $(LIB) $(MINILIB)
	gcc $(FLAGS) $(SRCS) -I ./minilibx_macos -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIB):
	make -C libft/

$(MINILIB):
	make -C minilibx_macos/

clean:
	make -C libft/ clean
	rm -f minilibx_macos/mlx_shaders.o minilibx_macos/mlx_new_window.o \
	minilibx_macos/mlx_init_loop.o minilibx_macos/mlx_new_image.o \
	minilibx_macos/mlx_xpm.o minilibx_macos/mlx_int_str_to_wordtab.o

fclean:
	rm -f $(NAME)
	make -C libft/ fclean
	make -C minilibx_macos/ clean

re: fclean all
