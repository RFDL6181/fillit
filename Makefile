# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdiglett <cdiglett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/29 18:54:58 by cdiglett          #+#    #+#              #
#    Updated: 2019/09/09 16:32:56 by cdiglett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			= fillit

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror

SRC			= dop.c highmoon.c input.c main.c result.c tetranos.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I fillit.h -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -I fillit.h

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all