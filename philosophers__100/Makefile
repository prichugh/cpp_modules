SRCS = main.c action.c init_data.c routine.c time.c utils.c

OBJS = $(SRCS:.c=.o)

NAME = philosophers

CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
