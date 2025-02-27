NAME = phonebook
CC = c++
SRCS = main.cpp Contact.cpp PhoneBook.cpp
CFLAGS = -Werror -Wall -Wextra -std=c++98
OBJS = $(SRC:.cpp=.o)


all: $(NAME)

$NAME: $(OBJ)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
