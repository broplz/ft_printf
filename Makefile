SRCS	=	ft_printf.c\
            srcs/ft_disp_char.c\
			srcs/ft_disp_hex.c\
			srcs/ft_disp_int.c\
			srcs/ft_disp_p.c\
			srcs/ft_disp_str.c\
			srcs/ft_disp_uint.c\
			srcs/ft_init.c\
			srcs/ft_int_len.c\
			srcs/ft_parse.c\
			srcs/ft_recursion.c\
			srcs/ft_io_utils.c\
			srcs/ft_lib_utils.c\

HEAD	=	includes/ft_printf.h

NAME	=	libftprintf.a

OBJS	=	$(SRCS:.c=.o)

GCC		= 	gcc
FLAG	=	-Wall -Wextra -Werror -g
RM		=	rm -f
C		=	-c
O		=	-o
AR		=	ar rc

all:		$(NAME)

.PHONY:		all clean fclean re

.c.o:
			$(GCC) $(FLAG) $(C) $< $(O) $(<:.c=.o)

$(NAME):	$(OBJS) $(HEAD)
			$(AR) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
