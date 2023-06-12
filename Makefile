# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmaturan <nmaturan@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/12 13:14:10 by nmaturan          #+#    #+#              #
#    Updated: 2023/06/12 13:15:30 by nmaturan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa

# Flags al compilar
FLAGS = -Wall -Wextra -Werror 

# Flags for linking
LNK = ar rc

# Include
INC = libft.h

# Functions
SRC = ft_printf.h 

# Objects

OBJ = $(SRC:.c=.o)

# Bonus

SRC_BONUS = ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c	ft_lstclear_bonus.c ft_lstdelone_bonus.c \
			ft_lstiter_bonus.c ft_lstnew_bonus.c ft_lstmap_bonus.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

#### Compilacion del programa ####

all: $(NAME)

$(NAME): $(OBJ) 
	$(LNK) $@ $^ 

%.o: %.c $(INC)
	gcc -c $(FLAGS) $< -o $@  

bonus: $(OBJ) $(OBJ_BONUS)
	$(LNK) $(NAME) $(OBJ) $(OBJ_BONUS)
	@touch bonus

fclean: clean
	@rm -f $(NAME) 

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)
	@rm -f bonus

re: fclean all

.PHONY: all clean fclean re
