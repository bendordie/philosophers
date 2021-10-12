# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cshells <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 18:13:52 by cshells           #+#    #+#              #
#    Updated: 2021/06/17 18:38:17 by cshells          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = philo.c \
	  philo_init.c \
	  philo_parser.c \
	  philo_simulation.c \
	  philo_spectator.c \
	  philo_utils.c \
	  ft_atoi.c

OBJ = $(SRC:.c=.o)

TAGS = -Wall -Wextra -Werror

CC = gcc -g

RM = rm -rf

all:	$(NAME)

$(NAME): $(SRC) $(OBJ) philo.h
	$(CC) $(TAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
