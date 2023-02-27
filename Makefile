SRCS	=	ft_printf.c	write_functions_nbr.c	write_functions_str.c	write_functions_hex.c

OBJS = ${SRCS:.c=.o}

HEAD = ft_printf/

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

LIB = ar rc

RM = rm -f

%.o: %.c  ${HEAD} Makefile
	gcc ${FLAGS} -I${HEAD} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} Makefile
	make -C libft
	cp libft/libft.a ./libftprintf.a
	${LIB} ${NAME} ${OBJS} libftprintf.a

clean:		
	${RM}  ${OBJS} a.out
	make clean -C libft

fclean:	clean 
	${RM} ${NAME} a.out
	make fclean -C libft

re:	fclean all

.PHONY: all clean fclean re