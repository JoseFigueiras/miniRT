NAME		= miniRT

INCLUDES	= ./includes/
SRCS		= minirt.c
OBJS		= $(SRCS:.c=.o)

all: $(OBJS)
	gcc	$(OBJS) -Lminilibx -lmlx_Linux  -lXext -lX11 -o $(NAME)

%.o: %.c
	gcc -c -I $(INCLUDES) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re bonus
