NAME		= SquareFinder

SRCS		=	pointsListsUtils.c		\
				squaresListsUtils.c		\
				generalUtils.c			\
				findSquares.c			\
				findSquaresBis.c		\

INCLUDES	= squares.h

CC			= clang

FRAMEWORK 	= -L$(LIBFT_PATH) -lft -lXext -lX11 -lm

CFLAGS		= -Wall -Wextra -Werror

MAKE		= make

LIBFT_PATH	= ./libft/

LIBFT		= $(LIBFT_PATH)/libft.a

OBJS		= ${SRCS:%.c=%.o}

%.o: %.c $(INCLUDES)
	@$(CC) $(CFLAGS) -c $< -o $@

all			:	lib ${NAME}

$(NAME)		: ${OBJS}
	$(CC) $(CFLAGS) -I./  $(OBJS) main.c -o $(NAME) $(FRAMEWORK)

lib			:
	$(MAKE) -C $(LIBFT_PATH)

clean		:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -f $(OBJS)

fclean		: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)

re			: fclean all

PHONY		: all clean fclean bonus comp re

