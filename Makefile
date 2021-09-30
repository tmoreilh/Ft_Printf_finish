NAME	= libftprintf.a

CC	= clang

CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

OBJS	= ${SRC:.c=.o}

INCLUDES= includes/

SRC	= ft_printf.c $(addprefix srcs/, ft_print_char.c ft_print_int.c \
ft_print_int_utils.c ft_print_maxihexa.c ft_print_minihexa.c \
ft_print_percent.c ft_print_pointer.c ft_print_string.c \
ft_print_uint.c parsing_printf.c print_type.c \
printf_utils.c printf_utils2.c printf_utils3.c)

%.o: %.c
	 ${CC} ${CFLAGS} -I$(INCLUDES) -c $< -o $@

all:	${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

bonus:	${NAME}

${NAME}: ${OBJS}

clean:
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

.PHONY:		all re clean fclean