SOURSES := ft_16.c ft_bzero.c \
                   ft_itoa.c \
                   ft_parce_char.c \
                   ft_parce_int.c \
                   ft_parce_n.c \
                   ft_parce_p.c \
                   ft_parce_properties.c \
                   ft_parce_types.c \
                   ft_parce_unsigned_int.c \
                   ft_parce_x.c \
                   ft_print_num.c \
                   ft_create_data.c \
                   ft_print_data.c \
                   ft_printf.c \
                   ft_putchar_fd.c \
                   ft_putstr_fd.c \
                   ft_strdup.c \
                   ft_strlen.c \
                   ft_uitoa.c \
                   ft_utils.c \

OBJECTS := $(SOURSES:%.c=%.o)

CC := gcc

CFLAGS := -Wall -Wextra -Werror

NAME := libftprintf.a

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@


all:		$(NAME)

bonus:		all

$(NAME):	$(OBJECTS)
			ar rc $(NAME) $(OBJECTS)

clean:
			rm -f $(OBJECTS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all


.PHONY : all clean fclean re