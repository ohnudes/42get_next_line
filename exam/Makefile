# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/25 21:29:07 by nmaturan          #+#    #+#              #
#    Updated: 2023/06/25 22:11:43 by nmaturan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = get_next_line.a

# Flags al compilar
FLAGS = -Wall -Wextra -Werror 

# Flags for linking
LNK = ar rc

# Include
INC = get_next_line.h

# Functions
SRC = get_next_line.c get_next_line_utils.c

# Objects
OBJ = $(SRC:.c=.o)

#### Compilacion del programa ####

all: $(NAME)

$(NAME): $(OBJ) 
	$(LNK) $@ $^ 

%.o: %.c $(INC)
	gcc -g -c $(FLAGS) $< -o $@  

fclean: clean
	@rm -f $(NAME) 

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
