# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 16:47:36 by yabukirento       #+#    #+#              #
#    Updated: 2024/09/08 13:20:54 by yabukirento      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBRARY_PRINTF = ./utils/libftprintf.a
SERVER = server
CLIENT = client
MAKE = make
SRCS_SERVER = server.c utils.c
SRCS_CLIENT = client.c utils.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: server client

server: $(OBJS_SERVER) $(LIBRARY_PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

client: $(OBJS_CLIENT) $(LIBRARY_PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBRARY_PRINTF):
	$(MAKE) -C ./utils

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	# rm -f $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	$(MAKE) -C ./utils clean

fclean: clean
	rm -f server client
	# rm -f server_bonus client_bonus
	$(MAKE) -C ./utils fclean

re: fclean all