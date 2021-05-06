NAME		=	miniRT

FLAGS		=	-Wall -Wextra -Werror
OBJDIR		=	/objs/
INCLUDES	=	-Iincludes

SRCS		=	minirt.c								\
				$(wildcard Libft/*.c)					\
				$(wildcard srcs/*/*.c)
			
OBJS		= 	$(SRCS:.c=.o)

all: $(OBJS)
	gcc $(FLAGS) $(OBJS) -Lminilibx -lmlx_Linux -lm -lXext -lX11 -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $< -c -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
