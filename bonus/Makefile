SRCS = main_bonus.c malloc_free_bonus.c pipes_fork_bonus.c strings_bonus.c strings_2_bonus.c
OBJBS = $(SRCS:.c=.o)
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
libft = ../libft

all : $(NAME)

$(NAME) : $(OBJBS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS)  ../libft/libft.a

%.o : %.c pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJBS)
fclean : clean
	rm -rf $(NAME)