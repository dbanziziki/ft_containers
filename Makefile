NAME = main

SRCS = main.cpp

CC = clang++

FLAGS = -g #-g -Wextra -Werror -Wall -std=c++98

all:
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
