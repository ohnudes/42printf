# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/07 19:05:10 by nmaturan          #+#    #+#              #
#    Updated: 2023/08/23 12:29:17 by ohadmin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test.a 

FLAGS = -Wall -Wextra -Werror

T_FLAGS = -Wall -Wextra -Werror -g

LNK = ar rcs

INC = ft_printf.h

SRC = ft_printf.c ft_printf_utils.c ft_printf_diuxp.c ft_printf_print.c \
	  ft_flags_utils.c

OBJ = $(SRC:.c=.o)

MAIN = ft_printf_bonus_test.c

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
	@gcc $(T_FLAGS) $(MAIN) $(NAME) -o prog.out

.PHONY: all clean fclean re
