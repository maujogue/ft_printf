SRCS = ft_atoi.c	ft_isascii.c	ft_memcmp.c	ft_putendl_fd.c\
	ft_strdup.c	ft_strlen.c	ft_substr.c	ft_bzero.c	ft_isdigit.c\
	ft_memcpy.c	ft_putnbr_fd.c	ft_striteri.c	ft_strmapi.c\
	ft_tolower.c	ft_calloc.c	ft_isprint.c	ft_memmove.c\
	ft_putstr_fd.c	ft_strjoin.c	ft_strnstr.c	ft_toupper.c\
	ft_isalnum.c	ft_itoa.c	ft_memset.c	ft_split.c	ft_strlcat.c\
	ft_strrchr.c	ft_isalpha.c	ft_memchr.c	ft_putchar_fd.c\
	ft_strchr.c	ft_strlcpy.c	ft_strtrim.c	ft_strncmp.c

SRCS_BONUS = ft_lstsize.c	ft_lstadd_front.c	ft_lstnew.c	ft_lstlast.c\
	ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c\
	ft_lstmap.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

HEAD = libft/

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

LIB = ar rc

RM = rm -f

.PHONY: all clean fclean re bonus

%.o:	%.c ${HEAD} Makefile
	${CC} ${FLAGS} -I${HEAD} -c $< -o $@  

all:	${NAME} Makefile

${NAME}:	${OBJS} 
	${LIB} ${NAME} ${OBJS} 

bonus:	${OBJS} ${OBJS_BONUS}
	${LIB} ${NAME} ${OBJS} ${OBJS_BONUS}

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean:	clean
	${RM} ${NAME}

re:	fclean	all
