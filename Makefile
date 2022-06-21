# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flazerak <flazerak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/18 15:22:13 by flazerak          #+#    #+#              #
#    Updated: 2022/06/18 18:56:49 by flazerak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client
LIB = minitalk.h
LIBS = bonus_minitalk.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
CFILES = utils.c
OBJ = $(CFILES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)

bonus:  $(OBJ) bonus_server bonus_client

bonus_server: $(LIBS) bonus_server.o
	$(CC) $(CFLAGS) bonus_server.o $(OBJ) -o $@

bonus_client: $(LIBS) bonus_client.o
	$(CC) $(CFLAGS) bonus_client.o $(OBJ)  -o $@

server: server.o
	$(CC) $(CFLAGS) server.o $(OBJ) -o $@

client: client.o 
	$(CC) $(CFLAGS) client.o $(OBJ)  -o $@

%.o:%.c $(LIB) $(LIBS)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM)  bonus_server.o server.o bonus_client.o client.o utils.o

fclean: clean
	$(RM) client bonus_client server bonus_server

re: fclean all