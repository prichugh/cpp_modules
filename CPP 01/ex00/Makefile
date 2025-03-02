NAME = zombies
CC = c++
CFLAGS = -Werror -Wall -Wextra -std=c++98
SRCS = main.cpp randomChump.cpp newZombie.cpp Zombie.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
