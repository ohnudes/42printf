# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/21 14:08:04 by nmaturan          #+#    #+#              #
#    Updated: 2023/09/19 17:44:31 by nmaturan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = libftprintf.a

# Flags al compilar
FLAGS = -g -Wall -Wextra -Werror 

# Flags for linking
LNK = ar rcs

# Include
INC = ft_printf.h

# Functions
SRC = ft_printf.c ft_printf_utils.c

# Objects
OBJ = $(SRC:.c=.o)

#### LIBFT
LFT_DIR = libft/
LIBFT = libft.a
DEPS = $(addprefix $(LFT_DIR), $(LIBFT))

MAIN = test.c

#### Compilacion del programa ####

all: $(NAME) makecheck

$(NAME): $(OBJ) 
	@echo Creating library: $(NAME)...
	@make -C $(LFT_DIR)
	@cp $(LFT_DIR)$(LIBFT) .
	@mv $(LIBFT) $(NAME)
	@$(LNK) $@ $(OBJ)
	@echo Library completed.

%.o: %.c $(INC)
	@echo Compiling $<...
	@gcc -c $(FLAGS) $< -o $@  
	@echo Compilation completed.

makecheck:
	@make -C $(LFT_DIR)

fclean: clean
	@rm -f $(NAME)

clean:
	@make -C $(LFT_DIR) fclean
	@rm -f $(OBJ)

re: fclean all

test: re clean
	@make clean
	@gcc -fsanitize=address $(FLAGS) $(MAIN) $(NAME) -o prog.out

.PHONY: all clean fclean re makecheck
