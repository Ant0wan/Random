NAME = tail

SRCS = srcs/main.c \
       srcs/ft_tail.c

O_FILES = main.o\
	  ft_tail.o

all: $(NAME)

$(NAME):
	gcc -Werror -Wall -Wextra $(SRCS) -c
	gcc $(O_FILES) -o $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)
