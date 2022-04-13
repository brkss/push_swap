
NAME = push_swap

CC 	= cc

CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c src/*.c

BSRCS = src/checker/*.c src/*.c

$NAME : all

all : 
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

bonus:
	$(CC) $(CFLAGS) $(BSRCS) -o checker

re: fclean all

clean:
	rm -f $(NAME)
	rm -f checker

fclean: clean
