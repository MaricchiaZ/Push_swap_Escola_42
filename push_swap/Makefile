NAME	= push_swap

CC	= cc
INCLUDE		= -I ./include
CFLAGS		= -g -Wall -Wextra -Werror $(INCLUDE)

RM	= rm -rf

PATH_SRCS	= ./src/
PATH_CHECK	= $(PATH_SRCS)check/
PATH_MAIN	= $(PATH_SRCS)main/
PATH_MOVES	= $(PATH_SRCS)moves/
PATH_ORDER	= $(PATH_SRCS)order/
PATH_UTILS	= $(PATH_SRCS)utils/
PATH_OBJS	= ./objs/

SRCS	= $(PATH_CHECK)check.c \
		$(PATH_ORDER)aux.c \
		$(PATH_ORDER)best_move.c \
		$(PATH_ORDER)exec_moves.c  \
		$(PATH_ORDER)order_hundred.c \
		$(PATH_ORDER)order_large_numbers.c \
		$(PATH_ORDER)order.c \
		$(PATH_ORDER)portion_info.c \
		$(PATH_MAIN)main.c \
		$(PATH_MOVES)move_p.c \
		$(PATH_MOVES)move_r.c \
		$(PATH_MOVES)move_rr.c \
		$(PATH_MOVES)move_s.c \
		$(PATH_UTILS)exit.c \
		$(PATH_UTILS)ft_array_dup.c \
		$(PATH_UTILS)ft_atolongi.c \
		$(PATH_UTILS)ft_calloc.c \
		$(PATH_UTILS)ft_sort_array.c \
		$(PATH_UTILS)ft_str_is_numeric.c \
		$(PATH_UTILS)ft_strcmp.c \

OBJS	= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o:	$(PATH_SRCS)%.c
		@mkdir -p $(PATH_OBJS)
		@mkdir -p $(PATH_OBJS)check/
		@mkdir -p $(PATH_OBJS)main/
		@mkdir -p $(PATH_OBJS)moves/
		@mkdir -p $(PATH_OBJS)order/
		@mkdir -p $(PATH_OBJS)utils/
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all $(PATH_OBJS) clean fclean re