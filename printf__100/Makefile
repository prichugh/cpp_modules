NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c\
		check_type.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_itoa.c\
		ft_uitoa.c\
		ft_puthex.c\
		ft_putptr.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
