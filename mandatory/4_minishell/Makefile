# Name of the executable
NAME = minishell

# Color definition for print purpose
BROWN=\$(COLOR_PREFIX)[0;33m
BLUE=\$(COLOR_PREFIX)[1;34m
END_COLOR=\$(COLOR_PREFIX)[0m

# Defines the C Compiler
CC := gcc

# Path of libraries Libft
LIBFT = $(LIBDIR)/libft
LIBFT_PATH = $(LIBFT)/libft.a

# Dependency libraries
LIBS := -I$(LIBFT)

# Flags for compiling
CFLAGS := -Werror -Wall -Wextra -g -g3 -MD

# Debug options
DEBUG := -g3 -DDEBUG=1

# Source code directory structure
BINDIR := bin
SRCDIR := src
LOGDIR := log
LIBDIR := libs
TESTDIR := test

# Source code file extension
BUILTIN := builtins/buitlins.c builtins/cd.c builtins/echo.c builtins/pwd.c \
			env/env.c env/export.c env/getenv.c env/setenv.c env/unset.c \
			getters/get_cmd.c getters/get_params.c \
			utils/my_subsplit.c utils/my_trim.c utils/utils.c utils/ft_atoi2.c \
			cmd_trim.c custom_cmd.c error.c expander.c heredoc.c main.c \
			nodes.c parse.c prompt.c signal.c

# %.o file names
NAMES := $(addprefix src/, $(BUILTIN))
OBJECTS := $(NAMES:%.c=%.o)

#
# COMPILATION RULES
#

default: all

# Help message
help:
	@echo "C Project Minishell"
	@echo
	@echo "Target rules:"
	@echo "    all      - Compiles and generates binary file"
	@echo "    tests    - Compiles with cmocka and run tests binary file"
	@echo "    valgrind - Runs binary file using valgrind tool"
	@echo "    clean    - Clean the project by removing binaries"
	@echo "    fclean   - Clean the project by removing the binaries and the executable"
	@echo "    help     - Prints a help message with target rules"


# Rule for link and generate the binary file
all: $(OBJECTS)
	make all -C $(LIBFT)/
	@echo -en "$(BROWN)LD $(END_COLOR)";
	$(CC) -lreadline -L .brew/opt/readline/lib -I .brew/opt/readline/include -o $+ $(DEBUG) $(CFLAGS) $(LIBS)

# Rule for run valgrind tool
valgrind:
	valgrind \
		--track-origins=yes \
		--leak-check=full \
		--leak-resolution=high \
		--log-file=$(LOGDIR)/$@.log \
		$(BINDIR)/$(BINARY)
	@echo -en "\nCheck the log file: $(LOGDIR)/$@.log\n"


# Rule for cleaning the project
clean:
	@echo "Deleting all the binaries files..."
	@rm -rvf $(OBJECTS)

# Rule for cleaning the project
fclean: clean
	@echo "Deleting the executable files..."
	@rm -rvf $(NAME);
