NAME = push_swap.a
SRCS = srcs/swap.c srcs/rotate.c srcs/revrotate.c srcs/push.c algorithm/sorting.c
OBJS = $(SRCS:.c=.o)
INCLUDE = includes
CC = cc -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf all
	cp ft_printf/libftprintf.a $(NAME)
	ar -rcs $(NAME) $(OBJS) ft_printf/libftprintf.a
	echo "${BOLD}${GREEN}Compilation successful${NO_COLOR}"

%.o: %.c
	$(CC) -I${INCLUDE} -c $< -o $@

clean: bclean
	make clean -C ft_printf
	rm -f $(OBJS)
	echo "${BOLD}${YELLOW}Cleaned all${NO_COLOR}"

fclean: clean
	make fclean -C ft_printf
	rm -f $(NAME)
	echo "${BOLD}${BLUE}All file cleaned${NO_COLOR}"

re: fclean all

bonus: $(BONUSOBJS)
	make -C ft_printf bonus
	cp ft_printf/libftprintf.a $(NAME)
	ar -rcs $(NAME) $(BONUSOBJS) ft_printf/libftprintf.a
	echo "${BOLD}${GREEN}Bonus compilation successful${NO_COLOR}"

bclean:
	rm -f $(BONUSOBJS)
	echo "${BOLD}${YELLOW}Bonus cleaned${NO_COLOR}"

.PHONY: all clean fclean re bonus