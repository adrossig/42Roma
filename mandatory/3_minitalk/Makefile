# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arossign <arossign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 15:42:14 by arossign          #+#    #+#              #
#    Updated: 2022/01/21 15:42:16 by arossign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRC = src/
INC = ./includes

CLIENT_FILES = main.c
SERVER_FILES = main.c
SHARED_FILES = utils.c utils_bonus.c

CLIENT_SRC = $(addprefix $(SRC)client/, $(CLIENT_FILES))
SERVER_SRC = $(addprefix $(SRC)server/, $(SERVER_FILES))
SHARED_SRC = $(addprefix $(SRC)shared/, $(SHARED_FILES))

CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_OBJ = $(SERVER_SRC:.c=.o)
SHARED_OBJ = $(SHARED_SRC:.c=.o)

#bonuses
BCLIENT = client_bonus
BSERVER = server_bonus

BCLIENT_FILES = main_bonus.c
BSERVER_FILES = main_bonus.c
BSHARED_FILES = utils.c utils_bonus.c

BCLIENT_SRC = $(addprefix $(SRC)client/, $(BCLIENT_FILES))
BSERVER_SRC = $(addprefix $(SRC)server/, $(BSERVER_FILES))
BSHARED_SRC = $(addprefix $(SRC)shared/, $(BSHARED_FILES))

BCLIENT_OBJ = $(BCLIENT_SRC:.c=.o)
BSERVER_OBJ = $(BSERVER_SRC:.c=.o)
BSHARED_OBJ = $(BSHARED_SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I$(INC)

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJ) $(SHARED_OBJ)
	@$(CC) $(CLIENT_OBJ) $(SHARED_OBJ) $(CFLAGS) -o $(CLIENT)

$(SERVER): $(SERVER_OBJ) $(SHARED_OBJ)
	@$(CC) $(SERVER_OBJ) $(SHARED_OBJ) $(CFLAGS) -o $(SERVER)

$(BCLIENT): $(BCLIENT_OBJ) $(BSHARED_OBJ)
	@$(CC) $(BCLIENT_OBJ) $(BSHARED_OBJ) $(CFLAGS) -o $(BCLIENT)

$(BSERVER): $(BSERVER_OBJ) $(BSHARED_OBJ)
	@$(CC) $(BSERVER_OBJ) $(BSHARED_OBJ) $(CFLAGS) -o $(BSERVER)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

bonus: $(BCLIENT) $(BSERVER)

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(SHARED_OBJ) $(BCLIENT_OBJ) $(BSERVER_OBJ) $(BSHARED_OBJ)

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(BCLIENT) $(BSERVER)

re:
	@make fclean
	@make all
