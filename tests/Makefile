NAME = push_swap
SRCS = srcs/swap.c srcs/rotate.c srcs/revrotate.c srcs/push.c algorithm/sorting.c main.c
INCLUDE = includes
CC = cc -g#-Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft all bonus
	$(CC) -I$(INCLUDE) $(SRCS) ./libft/libft.a -o $(NAME)
	echo "${BOLD}${GREEN}Compilation successful${NO_COLOR}"

clean: bclean
	make clean -C libft
	echo "${BOLD}${YELLOW}Cleaned all${NO_COLOR}"

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	echo "${BOLD}${BLUE}All file cleaned${NO_COLOR}"

re: fclean all

bonus: $(BONUSOBJS)
	make -C libft bonus
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(BONUSOBJS) libft/libft.a
	echo "${BOLD}${GREEN}Bonus compilation successful${NO_COLOR}"

bclean:
	rm -f $(BONUSOBJS)
	echo "${BOLD}${YELLOW}Bonus cleaned${NO_COLOR}"

.PHONY: all clean fclean re bonus
.SILENT:
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
NO_COLOR = \033[0m
BOLD = \033[1m
