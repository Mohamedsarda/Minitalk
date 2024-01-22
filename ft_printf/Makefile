CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_action.c	ft_printf.c	ft_putchar.c	ft_putnbr_base.c	ft_putstr.c\
ft_putnbr_hex.c ft_atoi.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

RM = rm -f

LIBC = ar rcs

all : $(NAME)

$(NAME) : $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)

%.o:%.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJS)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: fclean all clean re
