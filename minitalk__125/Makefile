SRCS	= client.c server.c helper.c\

OBJS	= $(SRCS:%.c=%.o)

CC		= cc
RM		= rm -f
CFLAGS 	= -Wall -Wextra -Werror

all:	server client

%.o:	%.c
		${CC} ${CFLAGS} -c $< -o $@

server: server.o helper.o
		${CC} ${CFLAGS} server.o helper.o -o server

client: client.o helper.o
		${CC} ${CFLAGS} client.o helper.o -o client

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} server client

re:		fclean all

.PHONY:	all clean fclean re
