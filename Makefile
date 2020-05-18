# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldu-pree <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 14:55:03 by ldu-pree          #+#    #+#              #
#    Updated: 2019/08/19 14:56:25 by ldu-pree         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INC_PATH = ./include/ ./libft/includes/
LIB_PATH = ./libft/

NAME_1 = push_swap
NAME_2 = checker
FLAGS = -Wall -Werror -Wextra
CC = gcc $(FLAGS)

SRC_1_NAME = checker_commands.c checker_flags.c checker_instruct.c \
			do_push.c do_reverse_rotate.c do_rotate.c do_swap.c error.c \
			move_position_2.c move_position.c position.c push_swap_main.c \
			represent_stack.c solver_2.c solver.c utilities.c \

SRC_2_NAME = checker_commands.c checker_flags.c checker_instruct.c checker_main.c \
			do_push.c do_reverse_rotate.c do_rotate.c do_swap.c error.c \
			move_position_2.c move_position.c position.c \
			represent_stack.c solver_2.c solver.c utilities.c \

OBJ_1_NAME = $(SRC_1_NAME:.c=.o)
OBJ_2_NAME = $(SRC_2_NAME:.c=.o)
LIB_NAME = libft.a

SRC_1 = $(addprefix $(SRC_PATH), $(SRC_1_NAME))
SRC_2 = $(addprefix $(SRC_PATH), $(SRC_2_NAME))
OBJ_1 = $(addprefix $(OBJ_PATH), $(OBJ_1_NAME))
OBJ_2 = $(addprefix $(OBJ_PATH), $(OBJ_2_NAME))
INC = $(addprefix -I, $(INC_PATH))
LIB = $(LIB_PATH)$(LIB_NAME)

all: $(NAME_1) $(NAME_2)

$(NAME_1): $(OBJ_1)
	make -C $(LIB_PATH) re
	$(CC) $(LIB) $(INC) $(OBJ_1) -o $(NAME_1)

$(NAME_2): $(OBJ_2)
	make -C $(LIB_PATH) re
	$(CC) $(LIB) $(INC) $(OBJ_2) -o $(NAME_2)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(INC) -o $@ -c $<

cleanlib:
	@make -C $(LIB_PATH) clean

fcleanlib:
	@make -C $(LIB_PATH) fclean

clean: cleanlib
	@rm -fv $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

norme:
	@make -C $(LIB_PATH) norme
	@norminetter $(SRC) ./includes/

	./objs/checker_commands.o ./objs/checker_flags.o ./objs/checker_instruct.o ./objs/do_push.o ./objs/do_reverse_rotate.o ./objs/do_rotate.o ./objs/do_swap.o ./objs/error.o ./objs/move_position_2.o ./objs/move_position.o ./objs/position.o ./objs/push_swap_main.o ./objs/represent_stack.o ./objs/solver_2.o ./objs/solver.o ./objs/utilities.o