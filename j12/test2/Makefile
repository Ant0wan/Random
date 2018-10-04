NAME = cat

SRCS = srcs/ft_cat.c \
       srcs/main.c

O_FILES = ft_cat.o \
	  main.o

all: $(NAME)

$(NAME):
	gcc $(SRCS) -c
	gcc $(O_FILES) -o cat

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)
