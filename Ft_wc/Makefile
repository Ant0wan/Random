NAME := ft_wc
CFLAGS += -Wall -Werror -Wextra -Wpedantic -g3 -ansi -D_POSIX_C_SOURCE -std=c89
#RELEASE += -O2 -fno-builtin
#DEBUG += -fsanitize=address

$(NAME): lex.yy.c Makefile
	$(CC) $(CFLAGS) lex.yy.c arg.c -lfl -o $(NAME)

lex.yy.c: wc.l
	flex wc.l

clean:
	$(RM) lex.yy.c ft_wc

fclean: clean

re: $(NAME)
