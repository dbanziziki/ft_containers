NAME = main

SRCS = main.cpp

TEST_SRCS = vector_test.cpp

CC = clang++

CRITERION = -l criterion -I ~/.brew/include -L ~/.brew/lib -std=c++11


FSAN = -fsanitize=address

FLAGS = -g -Wextra -Werror -Wall $(FSAN)  -std=c++98

all:
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

test: fclean vector_test.cpp vector.hpp
	$(CC) $(FLAGS) vector_test.cpp -o test
	./test

bst: fclean bst.hpp bst.cpp
	$(CC) $(FLAGS) bst.cpp -o bst
	./bst

map_test: fclean map.hpp tests/map_test.cpp
	$(CC) -g tests/map_test.cpp -I. -o $@ $(CRITERION)
	./$@

map: fclean map.hpp main.cpp
	$(CC) -g $(FSAN) $(FLAGS) main.cpp -o $@

fclean:
	rm -f $(NAME) test bst map