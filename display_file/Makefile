NAME := ft_display_file

SRCS := srcs/display_file

WARNINGS := -g -fsanitize=address -O2 -fno-builtin

all : 
	gcc $(WARNINGS) $(SRCS).c -c -o $(SRCS).o
	gcc $(WARNINGS) $(SRCS).o -o $(NAME)

clean :
	/bin/rm -f $(SRCS).o

fclean : clean
	/bin/rm -f $(NAME)
