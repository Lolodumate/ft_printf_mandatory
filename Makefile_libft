SRC =	ft_itoa.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_strchr.c \
	ft_strlen.c \

CC =	gcc

FLAGS = -Wall -Werror -Wextra

OBJ =	$(SRC:.c=.o)

NAME = libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	cc -nostartfiles -fPIC $(FLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re
