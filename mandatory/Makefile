SRCS = main.c malloc_free.c pipes_fork.c strings.c strings_2.c
OBJBS = $(SRCS:.c=.o)
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
libft = ../libft

all : $(NAME)

$(NAME) : $(OBJBS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS)  ../libft/libft.a

%.o : %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJBS)
fclean : clean
	rm -rf $(NAME)