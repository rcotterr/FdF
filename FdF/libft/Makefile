# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 18:33:13 by mmcclure          #+#    #+#              #
#    Updated: 2019/02/19 14:24:48 by mmcclure         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_PR_P = ./ft_printf/

SRCS_L_F = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
		ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
		ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c\
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
		ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strtrimchrs.c ft_strnewndata.c\
		ft_strchrcount.c ft_strsplitchrs.c ft_lstfind.c ft_lstpushback.c \
		ft_lstpushfront.c ft_lstsize.c ft_lstprint.c get_next_line.c \
		ft_putwchar.c ft_isspace.c\
		
SRCS_PR_F = ft_printf.c prf_format_slv.c prf_print_dioux.c prf_print_clcsls.c \
		prf_print_brk.c prf_print_float.c prf_print_pprec.c prf_get_numarg.c \
		prf_putunbr.c

SRCS = $(SRCS_L_F) $(addprefix $(SRCS_PR_P), $(SRCS_PR_F))

OBJ = $(SRCS_L_F:%.c=%.o) $(SRCS_PR_F:%.c=%.o)

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS) -I ./includes/
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
