NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = ./libft
PRINTF_PATH = ./printf
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

SRCS =	push_swap.c\
		ft_split.c\
		stack_inits.c\
		stack_utils.c\
		stack_errors.c\
		init_a.c\
		init_b.c\
		./Orders/push.c\
		./Orders/rotate.c\
		./Orders/reverse_rotate.c\
		./Orders/swaps.c\
		./Orders/sort_three.c\
		turk_algorithm.c\

OBJS = $(SRCS:%.c=%.o)


all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH) all

$(PRINTF):
	make -C $(PRINTF_PATH) all

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_PATH) clean
	make -C $(PRINTF_PATH) clean
fclean:
	rm -f $(NAME) $(LIBFT) $(PRINTF) $(OBJS)
	make -C $(LIBFT_PATH) fclean
	make -C $(PRINTF_PATH) fclean

re: fclean all