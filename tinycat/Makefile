NAME := tinycat

SRC := display_file.c

FLAGS += -Wall -Wextra -Werror -O2 -D_POSIX_C_SOURCE

CFLAGS += $(FLAGS) -ansi

LDFLAGS += $(FLAGS) -flto=full

%.o:%.c
	$(CC) $(SRC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(SRC) $(LDLAGS) $^ -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

