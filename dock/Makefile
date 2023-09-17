# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/30 18:36:37 by nmaturan          #+#    #+#              #
#    Updated: 2023/09/04 17:14:23 by nmaturan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a 

MAIN = main.c

FLAGS = -Wall -Wextra -Werror

T_FLAGS = -Wall -Wextra -Werror -g

LNK = ar rcs

INC = get_next_line.h

SRC = get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

# MAIN = ft_printf_bonus_test.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo Creating library: $(NAME) ...
	@$(LNK) $@ $(OBJ)
	@echo Library completed

%.o: %.c $(INC)
	@echo Compiling $<
	@gcc -c $(T_FLAGS) $< -o $@
	@echo Compilation complete.

fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJ)

re: fclean all

test: re
	@make clean
	@gcc -fsanitize=address $(T_FLAGS) $(MAIN) $(NAME) -o prog.out

.PHONY: all clean fclean re