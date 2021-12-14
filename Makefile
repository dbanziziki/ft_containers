NAME = main

SRCS = main.cpp

TEST_SRCS = vector_test.cpp

CC = clang++

FSAN = #-fsanitize=address

FLAGS = -g -Wextra -Werror -Wall $(FSAN)  -std=c++98

all:
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

test: vector_test.cpp vector.hpp
	$(CC) $(FLAGS) vector_test.cpp -o test

fclean:
	rm -f $(NAME) test