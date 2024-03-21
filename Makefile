SRCS = ./mandatory/main.c ./mandatory/malloc_free.c ./mandatory/pipes_fork.c ./mandatory/strings.c ./mandatory/strings_2.c
SRCS_BONUS = ./bonus/main_bonus.c ./bonus/malloc_free_bonus.c ./bonus/pipes_fork_bonus.c ./bonus/strings_bonus.c ./bonus/strings_2_bonus.c ./bonus/path_helper_bonus.c
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

%.o : %.c ./mandatory/pipex.h ./bonus/pipex_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	make clean -C ./libft
	rm -rf $(OBJBS) $(OBJBS_BONUS)

fclean : clean
	make fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
