# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorphan <lorphan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 15:27:49 by lorphan           #+#    #+#              #
#    Updated: 2022/01/18 15:37:50 by lorphan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= philo_bonus

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf

INCLUDES_DIR	= ./includes/
SOURCES_DIR		= ./sources/
OBJECTS_DIR		= ./objects/

INCLUDES		= $(wildcard $(addsuffix *.h, $(INCLUDES_DIR)))
SOURCES			= $(wildcard $(addsuffix *.c, $(SOURCES_DIR)))
OBJECTS			= $(addprefix $(OBJECTS_DIR), $(notdir $(patsubst %.c, %.o, $(SOURCES))))

VPATH = $(SOURCES_DIR)

$(OBJECTS_DIR)%.o: %.c $(INCLUDES)
					mkdir -p $(OBJECTS_DIR)
					$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(INCLUDES)  $(OBJECTS)
					$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
					$(RM) $(OBJECTS_DIR)

fclean:				clean
					$(RM) $(NAME)

bonus:				all

re:					fclean all