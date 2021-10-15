SRCS		=	srcs/ft_printf.c			\
				srcs/convert_char.c			\
				srcs/convert_int.c			\
				srcs/convert_percent.c		\
				srcs/convert_ptr.c			\
				srcs/convert_string.c		\
				srcs/convert_uint.c			\
				srcs/convert_hex.c			\
				srcs/ft_putnbr_base.c		\
				srcs/ft_strlen.c			\
				srcs/ft_write.c

INCLUDES	=	./includes

OBJS		=	${SRCS:.c=.o}

OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

NAME		=	libftprintf.a

CFLAGS		=	-Wall -Wextra -Werror

CC			=	gcc

RM			=	rm -f

.c.o:
				${CC} ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS}
				ar rc ${NAME} ${OBJS}

all:			${NAME}

bonus:			${NAME}

printf:
				${CC} ${CFLAGS} -I${INCLUDES} main.c ${SRCS} -o printf.out

clean:
				${RM} ${OBJS} ${OBJS_BONUS}

fclean:			clean
				${RM} ${NAME}
				${RM} printf.out

re:				fclean all

.PHONY:			all clean fclean re
