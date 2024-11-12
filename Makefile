# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdulba <sabdulba@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 11:05:57 by sabdulba          #+#    #+#              #
#    Updated: 2024/11/12 13:24:35 by sabdulba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
SRC = get_next_line.c get_next_line_utils.c
MAIN_OBJ = get_next_line.o
OBJ := $(SRC:%.c=%.o)
LIBC = ar rc $(NAME)
LIBR = ranlib $(NAME)
CC = cc
RM = rm -f
FLAG = -Wall -Wextra -Werror
EXEC = program

%.o : %.c get_next_line.h
	$(CC) $(FLAG) -c $< -o $@

$(NAME) : $(OBJ)
	$(LIBC) $(OBJ)
	$(LIBR)

all : $(NAME)

clean :
		$(RM) $(OBJ)

fclean : clean
		$(RM) $(NAME) $(EXEC)
		
re : fclean all

run : $(NAME) $(MAIN_OBJ)
	  $(CC)	$(FLAG) $(MAIN_OBJ) -L. -lgnl -o $(EXEC)
	  ./$(EXEC)