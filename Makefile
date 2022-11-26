NAME		= SquareFinder

SRCS		=	pointsListsUtils.c		\
				squaresListsUtils.c		\
				generalUtils.c			\
				findSquares.c			\

INCLUDES	= squares.h

CC			= clang

CFLAGS		= -Wall -Wextra -Werror -g3

MAKE		= make

OBJS		= ${SRCS:%.c=%.o}

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

all			:	${NAME}

$(NAME)		: ${OBJS}
	$(CC) $(CFLAGS) -I./ $(OBJS) main.c -L/usr/include -lm -o $(NAME)

clean		:
	rm -f $(OBJS)

fclean		: clean
	rm -f $(NAME)

re			: fclean all

PHONY		: all clean fclean bonus comp re