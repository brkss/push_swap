
NAME = push_swap

CC 	= cc

CFLAGS = -Wall -Werror -Wextra

FILES = src/atoi.c src/cases.c src/check.c src/error.c src/fill.c src/long.c src/moves.c src/print.c src/short.c src/sort.c src/utils.c


SRCS = push_swap.c 

BSRCS = src/checker/checker.c src/checker/get_next_line.c src/checker/get_next_line_utils.c src/checker/utils.c

all : $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(SRCS) $(FILES) -o $(NAME)

bonus:
	$(CC) $(CFLAGS) $(BSRCS) $(FILES) -o checker

re: fclean all

clean:
	rm -f $(NAME)
	rm -f checker

fclean: clean
