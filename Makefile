NAME		=	miniRT

FLAGS		=	-Wall -Wextra -Werror
OBJDIR		=	/objs/
INCLUDES	=	-Iincludes

SRCS		=	minirt.c			\
				$(wildcard srcs/**/*.c)
			
OBJS		= 	$(SRCS:.c=.o)

all: $(OBJS)
	gcc	$(OBJS) -Lminilibx -lmlx_Linux  -lXext -lX11 -o $(NAME)

%.o: %.c
	gcc $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re bonus
