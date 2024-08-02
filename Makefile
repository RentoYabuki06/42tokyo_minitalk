# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 16:47:36 by yabukirento       #+#    #+#              #
#    Updated: 2024/08/02 16:47:37 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SERVER = server
CLIENT = client
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
SRCS_SERVER_BONUS = server_bonus.c utils.c
SRCS_CLIENT_BONUS = client_bonus.c utils.c
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)


all: server client

server: $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o server $(OBJS_SERVER)

client: $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o client $(OBJS_CLIENT)

server_bonus: $(OBJS_SERVER_BONUS)
	$(CC) $(CFLAGS) -o server_bonus $(OBJS_SERVER_BONUS)

client_bonus: $(OBJS_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o client_bonus $(OBJS_CLIENT_BONUS)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	rm -f $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean: clean
	rm -f server client
	rm -f server_bonus client_bonus

re: fclean all

bonus: server_bonus client_bonus