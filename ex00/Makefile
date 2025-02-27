SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

NAME = megaphone

CC = c++

RM = rm -fdf

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.c
	$(CC) ($CFLAGS) -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
