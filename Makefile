SRCS = ./mandatory/main.c ./mandatory/malloc_free.c ./mandatory/pipes_fork.c ./mandatory/strings.c ./mandatory/strings_2.c
SRCS_BONUS = ./bonus/main_bonus.c ./bonus/malloc_free_bonus.c ./bonus/pipes_fork_bonus.c ./bonus/strings_bonus.c ./bonus/strings_2_bonus.c
OBJBS = $(SRCS:.c=.o)
OBJBS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJBS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS) ./libft/libft.a

bonus : $(OBJBS_BONUS)
	make -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJBS_BONUS) ./libft/libft.a

# Update the pattern rule to handle files in subdirectories
%.o : %.c pipex.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJBS) $(OBJBS_BONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
