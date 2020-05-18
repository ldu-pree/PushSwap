# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 11:31:09 by ldu-pree          #+#    #+#              #
#    Updated: 2019/08/23 12:22:13 by ldu-pree         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
CC = gcc $(FLAGS)
OBJ_PATH = ./objs/
INC_PATH = ./includes/
SRC_PATH = ./srcs/

SRC_NAME := ft_bzero.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcpy.c \
			ft_memset.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
			ft_isprint.c ft_memcmp.c ft_tolower.c ft_toupper.c ft_strcmp.c \
			ft_strncmp.c ft_atoi.c ft_islower.c ft_isupper.c ft_iswhitespace.c \
			ft_strcat.c ft_strcpy.c ft_strncat.c ft_strncpy.c ft_strnstr.c \
			ft_strchr.c ft_strrchr.c ft_strstr.c ft_strlen.c ft_strlcat.c \
			ft_memalloc.c ft_memdel.c ft_strclr.c ft_strdel.c ft_putchar.c \
			ft_putchar_fd.c ft_putstr.c ft_putstr_fd.c ft_putendl.c \
			ft_putendl_fd.c ft_striter.c ft_striteri.c ft_putnbr.c \
			ft_putnbr_fd.c ft_strequ.c ft_strnequ.c ft_countwords.c \
			ft_itoa.c ft_strtrim.c ft_strsub.c ft_strnew.c ft_strjoin.c \
			ft_strsplit.c ft_strmap.c ft_strmapi.c ft_strdup.c ft_strndup.c \
			ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
			ft_lstnew.c ft_atof.c get_next_line.c \

OBJ_NAME := $(SRC_NAME:.c=.o) #everything in File, but change .c to .o

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

.PHONY: clean

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) -I$(INC_PATH) -o $@ -c $<

$(NAME): $(OBJ) $(INC_PATH)  #libft.a: ft_atoi.o
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Panda built a bunny"

clean:
	@rm -f $(OBJ)
	@rm -f .o
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "Panda ate a bunny"

fclean: clean
	@rm -f $(NAME)
	@echo "Panda laid schematics for a bunny"

re: fclean all
