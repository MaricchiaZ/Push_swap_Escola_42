NAME	= push_swap

CC	= cc
INCLUDE		= -I ./
CFLAGS		= -g -Wall -Wextra -Werror $(INCLUDE) ## flags que a 42 pede

RM	= rm -rf

PATH_SRCS	= ./ ## caminho para os arquivos
PATH_UTILS	= $(PATH_SRCS)utils/ ## caminho para os arquivos auxiliares
PATH_OBJS	= ./objs/

SRCS	= ./main.c \
		./check.c \
		./move_s.c \
		./move_p.c \
		./move_r.c \
		./move_rr.c \
		./exec_moves.c \
		./order.c \
		./order_hundred.c \
		./order_large_numbers.c \
		./aux.c \
		$(PATH_UTILS)ft_str_is_numeric.c \
		$(PATH_UTILS)ft_atolongi.c \
		$(PATH_UTILS)ft_sort_array.c \
		$(PATH_UTILS)ft_array_dup.c \
		$(PATH_UTILS)ft_strcmp.c \
		$(PATH_UTILS)ft_calloc.c \

OBJS	= $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS)) ## regra para criar os objs

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

$(PATH_OBJS)%.o:	$(PATH_SRCS)%.c  ## cria os objs dentro das pastas adequadas
		@mkdir -p $(PATH_OBJS) 
		@mkdir -p $(PATH_OBJS)utils/
		$(CC) $(CFLAGS) -c $< -o $@

clean: ## apaga os o. e as pastas dos .o
	$(RM) ./objs

fclean: clean ## apaga os o. e as pastas dos .o MAIS o executável
	$(RM) $(NAME)

re:	fclean all ## apaga os o., as pastas dos .o e o executável E recompila tudo

.PHONY:	all $(PATH_OBJS) clean fclean re ## evita conflito se tiver nome de regra e arquivo igual