NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = atoi2.c check_argument.c count_nodes.c create_stack.c error_msg.c find_cheapest_to_push.c\
find_correct_spot.c free_args.c free_stack.c ft_split.c ft_strcmp.c ft_strlcpy.c ft_strncmp.c\
int_range.c manipulate_a_and_b.c manipulate_stack_a.c manipulate_stack_b.c max_and_min.c\
move_cheapest.c move_cheapest_cont.c node_index.c push_swap.c sort_algorithm.c top_or_bot.c\

OBJ = $(SRCS:.c=.o)

all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
