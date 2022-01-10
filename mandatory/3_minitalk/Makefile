# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrossig <adrossig@students.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 19:04:05 by adrossig          #+#    #+#              #
#    Updated: 2021/05/29 11:04:52 by adrossig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRC = src/
INC = ./includes

CLIENT_FILES = main.c
SERVER_FILES = main.c
SHARED_FILES = utils.c

CLIENT_SRC = $(addprefix $(SRC)client/, $(CLIENT_FILES))
SERVER_SRC = $(addprefix $(SRC)server/, $(SERVER_FILES))
SHARED_SRC = $(addprefix $(SRC)shared/, $(SHARED_FILES))

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
SHARED_OBJ = $(SHARED_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(SHARED_OBJ)
	@$(CC) $(CLIENT_OBJ) $(SHARED_OBJ) $(CFLAGS) -o $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(SHARED_OBJ)
	@$(CC) $(SERVER_OBJ) $(SHARED_OBJ) $(CFLAGS) -o $(SERVER)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(SHARED_OBJ)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)

re:
	@make fclean
	@make all
