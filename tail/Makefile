NAME = tail

SRCS = srcs/main.c \
       srcs/ft_tail.c \
       srcs/ft_putstr.c

O_FILES = main.o \
	  ft_tail.o \
	  ft_putstr.o

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra $(SRCS) -c
	gcc $(O_FILES) -o $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)
