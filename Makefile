LIB = libftprintf.a
SRC = ft_hexa_p.c ft_putchar_printf.c ft_putu_printf.c\
ft_hexa.c ft_printf.c ft_putnbr_printf.c\
ft_hexa_maj.c ft_putstr_printf.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all : $(LIB)

$(LIB) : $(OBJ)
	$(AR) $(LIB) $(OBJ)
%.o : %.c ft_printf.h
	cc $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(LIB)
re: fclean all