NAME = libftprintf.a
SRCS = srcs/ft_printf.c srcs/parsing.c
CC = cc -Wall -Wextra -Werror -g
OBJS = $(SRCS:.c=.o)
INCLUDE = includes
BONUSSRCS = bonus/ft_printf_bonus.c bonus/parsing_bonus.c \
	bonus/ft_char_bonus.c bonus/ft_int_bonus.c bonus/ft_string_bonus.c \
	bonus/ft_int_utils_bonus.c bonus/ft_pointer_bonus.c bonus/ft_unsigned_bonus.c \
	bonus/ft_hexa_bonus.c

BONUSOBJS = $(BONUSSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft bonus
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS) libft/libft.a
	echo "${BOLD}${GREEN}Compilation successful${NO_COLOR}"

%.o: %.c
	$(CC) -I${INCLUDE} -c $< -o $@

clean: bclean
	make clean -C libft
	rm -f $(OBJS)
	echo "${BOLD}${YELLOW}Cleaned all${NO_COLOR}"

fclean: clean
	make fclean -C libft
	rm -f $(NAME)
	echo "${BOLD}${BLUE}All file cleaned${NO_COLOR}"

re: fclean all

bonus: $(BONUSOBJS)
	make -C libft all
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