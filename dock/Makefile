# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 19:22:53 by nmaturan          #+#    #+#              #
#    Updated: 2023/06/17 22:23:46 by nmaturan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = libftprintf.a

# Flags al compilar
FLAGS = -Wall -Wextra -Werror 

# Flags for linking
LNK = ar rc

# Include
INC = ft_printf.h

# Functions
SRC = ft_printf.c ft_printf_utils.c ft_print_control.c

# Objects

OBJ = $(SRC:.c=.o)

#### Compilacion del programa ####

all: $(NAME)

$(NAME): $(OBJ) 
	$(LNK) $@ $^ 

%.o: %.c $(INC)
	gcc -c $(FLAGS) $< -o $@  

fclean: clean
	@rm -f $(NAME) 

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
