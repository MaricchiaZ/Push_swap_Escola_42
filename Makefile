NAME	= push_swap

CC	= cc
INCLUDE		= -I ./
CFLAGS		= -g -Wall -Wextra -Werror $(INCLUDE)

RM	= rm -rf

PATH_SRCS	= ./
PATH_UTILS	= $(PATH_SRCS)utils/
PATH_OBJS	= ./objs/

SRCS	= ./main.c \
		./check.c \
		./move_s.c \
		./move_p.c \
		./move_r.c \
		./move_rr.c \
		./order.c \
		$(PATH_UTILS)ft_str_is_numeric.c \
		$(PATH_UTILS)ft_atolongi.c \
		$(PATH_UTILS)ft_sort_array.c \
		$(PATH_UTILS)ft_array_dup.c \
		$(PATH_UTILS)ft_array_cmp.c \
		#$(PATH_UTILS)ft_strlen.c \
		$(PATH_UTILS)ft_split.c \
		$(PATH_UTILS)ft_strlcpy.c \

OBJS	= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o:	$(PATH_SRCS)%.c
		@mkdir -p $(PATH_OBJS)
		@mkdir -p $(PATH_OBJS)utils/
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) ./objs

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all $(PATH_OBJS) clean fclean re