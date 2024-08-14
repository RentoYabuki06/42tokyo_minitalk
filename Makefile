# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 16:47:36 by yabukirento       #+#    #+#              #
#    Updated: 2024/08/14 22:25:10 by yabukirento      ###   ########.fr        #
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
# SRCS_SERVER_BONUS = server_bonus.c utils.c
# SRCS_CLIENT_BONUS = client_bonus.c utils.c
# OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
# OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)


all: server client

server: $(OBJS_SERVER) $(LIBRARY_PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

client: $(OBJS_CLIENT) $(LIBRARY_PRINTF)
	$(CC) $(CFLAGS) $^ -o $@

$(LIBRARY_PRINTF):
	$(MAKE) -C ./utils

# server_bonus: $(OBJS_SERVER_BONUS)
# 	$(CC) $(CFLAGS) -o server_bonus $(OBJS_SERVER_BONUS)

# client_bonus: $(OBJS_CLIENT_BONUS)
# 	$(CC) $(CFLAGS) -o client_bonus $(OBJS_CLIENT_BONUS)

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	# rm -f $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	$(MAKE) -C ./utils clean

fclean: clean
	rm -f server client
	# rm -f server_bonus client_bonus
	$(MAKE) -C ./utils fclean

re: fclean all

# bonus: server_bonus client_bonus