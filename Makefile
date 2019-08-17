# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalexand <nalexand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 20:36:34 by nalexand          #+#    #+#              #
#    Updated: 2019/08/17 20:54:01 by nalexand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VPATH = src/:includes/

NAME = destr

HEADERS = destr.h op.h params.h

LIB = destr.a

SRC = 	destr.c \
		op.c \
		setters.c \
		byte_functions.c \
		ft_reverse_bytes.c

OBJ_DIR = obj/

OBJ = $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))

all: $(NAME)

$(NAME): $(LIB)
	gcc -o $@ $^

$(LIB): $(OBJ)
	ar rc $@ $^

$(OBJ_DIR)%.o: %.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	gcc -o $@ -c $< -I includes

clean:
	rm -rf $(OBJ_DIR)
	rm -f $(LIB)

fclean: clean
	rm -f $(NAME)

re: fclean all
