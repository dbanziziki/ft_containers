NAME = main

SRCS = main.cpp

TEST_SRCS = vector_test.cpp

CC = clang++

CRITERION = -l criterion -I ~/.brew/include -L ~/.brew/lib -std=c++11


FSAN = #-fsanitize=address

FLAGS = -g -Wextra -Werror -Wall $(FSAN)  -std=c++98

all:
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

test: fclean vector_test.cpp vector.hpp
	$(CC) $(FLAGS) vector_test.cpp -o test
	./test

map: fclean map.hpp map_playground.cpp
	$(CC) $(FLAGS) map_playground.cpp -o map

map_test: fclean map.hpp tests/map_test.cpp
	$(CC) -g tests/map_test.cpp -I. -o $@ $(CRITERION)
	./$@ --verbose


vec_test: fclean vector.hpp tests/vector_test.cpp
	$(CC) -g tests/vector_test.cpp -I. -o $@ $(CRITERION)
	./$@

play: fclean map.hpp main.cpp
	$(CC) -g $(FSAN) $(FLAGS) main.cpp -o $@

bench: fclean map.hpp main_19.cpp
	$(CC) -g $(FSAN) $(FLAGS) main_19.cpp -o $@

fclean:
	rm -f $(NAME) test bst map map_test play vec_test

pair: pair_test.cpp utils.hpp
	$(CC) -g pair_test.cpp -o $@
