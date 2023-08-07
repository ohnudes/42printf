# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 19:05:10 by nmaturan          #+#    #+#              #
#    Updated: 2023/08/07 20:08:43 by nmaturan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test.a 

FLAGS = -Wall -Wextra -Werror -g

LNK = ar rcs

INC = ft_printf.h

SRC = ft_printf.c ft_printf_utils.c ft_print_diuxp.c ft_printf_cs.c

OBJ = $(SRC:.c=.o)

MAIN = ft_printf_bonus_test.c

all: $(NAME)

$(NAME): $(OBJ)
	@echo Creating library: $(NAME) ...
	@$(LNK) $@ $(OBJ)
	@echo Library completed

%.o: %.c $(INC)
	@echo Compiling $<
	@gcc -c $(FLAGS) $< -o $@
	@echo Compilation complete.


fclean: clean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJ)

re: fclean all

test: re
	@make clean
	@gcc $(FLAGS) $(MAIN) $(NAME) -o test.out 

.PHONY: all clean fclean re
