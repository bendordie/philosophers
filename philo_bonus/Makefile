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

NAME = philo_bonus

SRC = philo_bonus.c \
	  philo_init_bonus.c \
	  philo_parser_bonus.c \
	  philo_simulation_bonus.c \
	  philo_spectator_bonus.c \
	  philo_utils_bonus.c \
	  ft_atoi_bonus.c

OBJ = $(SRC:.c=.o)

TAGS = -Wall -Wextra -Werror

CC = gcc -g

RM = rm -rf

all:	$(NAME)

$(NAME): $(SRC) $(OBJ) philo_bonus.h
	$(CC) $(TAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
