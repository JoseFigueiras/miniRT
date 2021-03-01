NAME		= miniRT

SRCS		= main.c
OBJS		= $(SRCS:.c=.o)
all:
	gcc -c main.c -o main.o
	gcc main.c -Lminilibx -lmlx_Linux -lm -lXext -lX11

.PHONY: all clean fclean re bonus
