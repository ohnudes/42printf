# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 19:22:53 by nmaturan          #+#    #+#              #
#    Updated: 2023/06/19 16:41:56 by nmaturan         ###   ########.fr        #
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
LFTDIR = libft/
LIBFT = libft.a

#### Compilacion del programa ####

all: $(NAME) 

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT)
	@echo Creating library...
	@cp $(LFTDIR)$(LIBFT) $(NAME)
	@$(LNK) $@ $(OBJ)
	@echo Library completed.

$(LFTDIR)$(LIBFT): $(LIBFTDIR)Makefile
	@echo Compiling LIBFT...
	make -C ./$(LFTDIR)
	@echo LIBFT compiled

%.o: %.c $(INC)
	@echo Compiling ft_printf sources into .o
	@gcc -c $(FLAGS) $< -o $@  
	@echo Compilation finished

fclean: clean
	@rm -f $(NAME)

clean:
	@make -C $(LFTDIR) fclean
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
