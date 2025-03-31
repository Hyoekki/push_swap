CC = cc
NAME = push_swap
FLAGS = -Wall -Werror -Wextra -O2
SRCS = push_swap.c quicksort.c reverse_rotate.c rotate.c swap.c push.c validate_input.c get_pivot.c sort_three.c sort_five.c sort_a.c sort_b.c
OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
