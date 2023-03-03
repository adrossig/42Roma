SRC_VECTOR = my_containers/my_vector_tests.cpp

SRC_MAP = my_containers/my_map_tests.cpp

SRC_STACK = my_containers/my_stack_tests.cpp

SRC_STD_VECTOR = std_containers/std_vector_tests.cpp

SRC_STD_MAP = std_containers/std_map_tests.cpp

SRC_STD_STACK = std_containers/std_stack_tests.cpp

SRC_SET = my_containers/my_set_tests.cpp

SRC_STD_SET = std_containers/std_set_tests.cpp

C++ = clang++
CCFLAGS = -Wall -Wextra -Werror -std=c++98

MY_VECTOR_NAME = my_vec
MY_MAP_NAME = my_map
MY_STACK_NAME = my_stack
MY_SET_NAME = my_set

STD_VECTOR_NAME = std_vec
STD_MAP_NAME = std_map
STD_STACK_NAME = std_stack
STD_SET_NAME = std_set

RM = rm -rf

all	: $(MY_VECTOR_NAME) $(MY_MAP_NAME) $(MY_STACK_NAME) $(MY_SET_NAME) $(STD_VECTOR_NAME) $(STD_MAP_NAME) $(STD_STACK_NAME) $(STD_SET_NAME)

$(MY_VECTOR_NAME) :
	$(C++) $(CCFLAGS) $(SRC_VECTOR) -o $(MY_VECTOR_NAME)

$(MY_MAP_NAME) :
	$(C++) $(CCFLAGS) $(SRC_MAP) -o $(MY_MAP_NAME)

$(MY_STACK_NAME) :
	$(C++) $(CCFLAGS) $(SRC_STACK) -o $(MY_STACK_NAME)

$(MY_SET_NAME) :
	$(C++) $(CCFLAGS) $(SRC_SET) -o $(MY_SET_NAME)

$(STD_VECTOR_NAME) :
	$(C++) $(CCFLAGS) $(SRC_STD_VECTOR) -o $(STD_VECTOR_NAME)

$(STD_MAP_NAME) :
	$(C++) $(CCFLAGS) $(SRC_STD_MAP) -o $(STD_MAP_NAME)

$(STD_STACK_NAME) :
	$(C++) $(CCFLAGS) $(SRC_STD_STACK) -o $(STD_STACK_NAME)

$(STD_SET_NAME) :
	$(C++) $(CCFLAGS) $(SRC_STD_SET) -o $(STD_SET_NAME)

fclean:
	$(RM) *.dSYM
	$(RM) $(MY_VECTOR_NAME)
	$(RM) $(MY_MAP_NAME)
	$(RM) $(MY_STACK_NAME)
	$(RM) $(MY_SET_NAME)
	$(RM) $(STD_VECTOR_NAME)
	$(RM) $(STD_MAP_NAME)
	$(RM) $(STD_STACK_NAME)
	$(RM) $(STD_SET_NAME)

re: fclean all


