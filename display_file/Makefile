NAME := display_file

SRCS := srcs/display_file.c \

CFLAGS += -ansi -Wall -Wextra -Werror -fno-builtin -O2

%.o:%.c Makefile
	$(CC) -c $(WARNINGS) $(SRCS) $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(WARNINGS) $(SRCS) $^ -o $@
clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)
