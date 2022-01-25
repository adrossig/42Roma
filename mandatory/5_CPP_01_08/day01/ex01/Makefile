NAME			= zombie
SOURCE			= Zombie.cpp ZombieHorde.cpp main.cpp
OBJECT			= $(SOURCE:.cpp=.o)
COMPILE			= clang++
FLAGS			= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	@echo "$(GREY)Compiling...				$<"
	@$(COMPILE) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECT)
	@$(COMPILE) $(FLAGS) $(OBJECT) -o $(NAME)
	@echo "Executable				./$(NAME)"

clean:
	@/bin/rm -f $(OBJECT)
	@echo "REMOVED O-FILES"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "REMOVED EXECUTABLE FILE"

re: fclean all

.PHONY: all clean fclean re