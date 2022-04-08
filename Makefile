
NAME = push_swap

CC 	= cc

CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c src/*.c

$NAME : all

all : 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

re: fclean all

clean:
	rm -f $(NAME)

fclean: clean
