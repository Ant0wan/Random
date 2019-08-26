NAME := display_file

SRCS := srcs/display_file.c \

CFLAGS += -ansi -Wall -Wextra -Werror -fno-builtin -O2 -D_POSIX_C_SOURCE

%.o:%.c Makefile
	$(CC) -c $(CFLAGS) $(SRCS) $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(SRCS) $^ -o $@
clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)
