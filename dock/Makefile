# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 19:22:53 by nmaturan          #+#    #+#              #
#    Updated: 2023/06/19 17:37:40 by nmaturan         ###   ########.fr        #
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

#### LIBFT
LIBFT_DIR = libft/
LIBFT = libft.a

#### Compilacion del programa ####

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_DIR)$(LIBFT)
	@echo Creating library...
	@$(LNK) $@ $(OBJ) $(LIBFT_DIR)$(LIBFT)
	@echo Library completed.

$(LIBFT_DIR)$(LIBFT): $(LIBFTDIR)Makefile
	@echo Compiling LIBFT...
	make -C ./$(LIBFT_DIR)
	@echo LIBFT compiled

%.o: %.c $(INC)
	@echo Compiling ft_printf sources into .o
	@gcc -c $(FLAGS) $< -o $@  
	@echo Compilation finished

fclean: clean
	@rm -f $(NAME)

clean:
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
