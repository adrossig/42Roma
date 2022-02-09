# Name of the executable
NAME = minishell

# Color definition for print purpose
BROWN=\$(COLOR_PREFIX)[0;33m
BLUE=\$(COLOR_PREFIX)[1;34m
END_COLOR=\$(COLOR_PREFIX)[0m

# Defines the C Compiler
CC := gcc

# Dependency libraries
LIBS := -I$(LIBFT)

# Flags for compiling
CFLAGS := -Werror -Wall -Wextra -g -g3

# Debug options
DEBUG := -g3 -DDEBUG=1

# Source code directory structure
BINDIR := bin
SRCDIR := src
LOGDIR := log
LIBDIR := lib
TESTDIR := test

# Path of libraries Libft
LIBFT = $(LIBDIR)/libft
LIBFT_PATH = $(LIBFT)/libft.a

# Source code file extension
BUILTIN := c

SRCEXT := $(addprefix builtin/, $(BUILTIN))

# %.o file names
NAMES := $(addprefix src/, $(SRCEXT))
OBJECTS := $(SRC:%.c=%.o)

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
	@echo -en "$(BROWN)LD $(END_COLOR)";
	$(CC) -o $+ $(DEBUG) $(CFLAGS) $(LIBS)

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
