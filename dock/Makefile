# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/13 19:22:53 by nmaturan          #+#    #+#              #
#    Updated: 2023/06/19 16:29:28 by nmaturan         ###   ########.fr        #
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
# libft
LIBFT = libft.a

# path
LFTDIR = libft/

#### Compilacion del programa ####

all: $(NAME) 

$(NAME): $(OBJ) $(LFTDIR)$(LIBFT)
	cp $(LFTDIR)$(LIBFT) $(NAME)
	$(LNK) $@ $(OBJ)

$(LFTDIR)$(LIBFT): $(LIBFTDIR)Makefile
	make -C ./$(LFTDIR)

%.o: %.c $(INC)
	gcc -c $(FLAGS) $< -o $@  

fclean: clean
	@make -C $(LFTDIR) fclean
	@rm -f $(NAME)

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all clean fclean re
