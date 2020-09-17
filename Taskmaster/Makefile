CFLAGS += -lreadline -Werror -Wall -Wextra -g3 -std=c99 -D_GNU_SOURCE -D_POSIX_JOB_CONTROL -D_POSIX_C_SOURCE=200112L
CFLAGS += -fsanitize=address

SERVER := server
SERVER_OBJ := server.o

CLIENT := client
CLIENT_OBJ := client.o

all : parser $(SERVER) $(CLIENT)

parser: force
	@make -C Json-to-C

force:

$(CLIENT) : $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(CLIENT)
	@printf "\e[32m$@ built\e[0m\n"

$(SERVER) : $(SERVER_OBJ)
	@$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(SERVER)
	@printf "\e[32m$@ built\e[0m\n"

%.o : %.c
	@$(CC) $(CFLAGS) $< -c

clean :
	@$(RM) -f $(SERVER_OBJ) $(CLIENT_OBJ)
	@make clean -C Json-to-C
	@printf "\e[31mclean done\e[0m\n"

fclean : clean
	@$(RM) -f $(SERVER) $(CLIENT)
	@make fclean -C Json-to-C
	@printf "\e[31mfclean done\e[0m\n"

re : fclean all

.PHONY: all clean fclean re parser
