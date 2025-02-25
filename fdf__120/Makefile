NAME = fdf

CC = cc

CFLAGS  = -Wall -Wextra -Werror -I./minilibx-linux

LDFLAGS = -L./minilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm

SRCS = bresenham.c check_type.c cleanup.c color.c draw.c ft_atoi.c\
ft_itoa.c ft_printf.c ft_putchar.c ft_puthex.c ft_putptr.c\
ft_putstr.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c\
ft_strlcpy.c ft_strlen.c ft_uitoa.c get_next_line.c handle_keysym.c\
handle_menu.c init_window.c main.c math_utilities.c parse_map.c\
pixel_put.c set_data.c transform.c validate_input.c\

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): minilibx-linux $(OBJ)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

minilibx-linux:
	@if [ ! -d "minilibx-linux" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git minilibx-linux; \
	fi
	@$(MAKE) -C minilibx-linux

%.o: %.c
	$(CC) -c $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C minilibx-linux

fclean: clean
	rm -f $(NAME)
	make clean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re
