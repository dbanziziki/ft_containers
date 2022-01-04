NAME = main

SRCS = main.cpp

TEST_SRCS = vector_test.cpp

CC = clang++

FSAN = #-fsanitize=address

FLAGS = -g -Wextra -Werror -Wall $(FSAN)  -std=c++98

all:
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

test: fclean vector_test.cpp vector.hpp
	$(CC) $(FLAGS) vector_test.cpp -o test
	./test

bst: bst.hpp bst.cpp
	$(CC) $(FLAGS) bst.cpp -o bst

map: map.hpp map_test.cpp
	$(CC) $(FLAGS) map_test.cpp -o map

fclean:
	rm -f $(NAME) test bst map