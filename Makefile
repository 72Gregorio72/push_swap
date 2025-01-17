NAME = push_swap
BONUS_NAME = checker
SRCS = srcs/swap.c srcs/rotate.c \
	srcs/revrotate.c srcs/push.c \
	algorithm/sorting.c \
	algorithm/parsing.c \
	algorithm/main_utils.c \
	algorithm/main_utils2.c \
	algorithm/sorting_utils.c \
	algorithm/sorting_utils2.c \
	algorithm/sorting_utils3.c \
	algorithm/sorting_utils4.c \
	algorithm/do_moves_utils.c \
	algorithm/do_moves.c 

BONUS = bonus/push_swap_bonus.c bonus/push_bonus.c bonus/push_swap_utils_bonus.c
INCLUDE = includes
CC = cc -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft all bonus
	$(CC) -I$(INCLUDE) $(SRCS) main.c ./libft/libft.a -o $(NAME)
	echo "${BOLD}${GREEN}Compilation successful${NO_COLOR}"

bonus: $(BONUS)
	make -C libft all bonus
	$(CC) -I$(INCLUDE) $(SRCS) $(BONUS) ./libft/libft.a -o $(BONUS_NAME)
	echo "${BOLD}${GREEN}Bonus compilation successful${NO_COLOR}"

clean: bclean
	make clean -C libft
	echo "${BOLD}${YELLOW}Cleaned all${NO_COLOR}"

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	echo "${BOLD}${BLUE}All file cleaned${NO_COLOR}"

re: fclean all

bclean:
	rm -f $(BONUS_NAME)
	echo "${BOLD}${YELLOW}Bonus cleaned${NO_COLOR}"

.PHONY: all clean fclean re bonus
.SILENT:
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
NO_COLOR = \033[0m
BOLD = \033[1m
