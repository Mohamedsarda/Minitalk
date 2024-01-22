FT_PRINTF_PATH  =   ft_printf/
FT_PRINTF_HEADER  =  ft_printf/ft_printf.h
FT_PRINTF_LIB   =   libftprintf.a
FT_PRINTF       =   $(FT_PRINTF_PATH)$(FT_PRINTF_LIB)

SERVER          =   server
CLIENT          =   client

SRCS = ft_printf/ft_action.c	ft_printf/ft_printf.c	ft_printf/ft_putchar.c	ft_printf/ft_putnbr_base.c	ft_printf/ft_putstr.c\
ft_printf/ft_putnbr_hex.c ft_printf/ft_atoi.c

SERVER_BONUS    =   server_bonus
CLIENT_BONUS    =   client_bonus

CC              =   cc
FLAGS           =   -Wall -Werror -Wextra
RM              =   rm -f
AR              =   ar rcs
INCLUDE         =   -I ./$(FT_PRINTF_PATH)

SERVER_OBJS     =   server.o
CLIENT_OBJS     =   client.o

SERVER_BONUS_OBJS     =   server_bonus.o
CLIENT_BONUS_OBJS     =   client_bonus.o

all: $(FT_PRINTF) $(SERVER) $(CLIENT) 

$(FT_PRINTF): $(FT_PRINTF_HEADER) $(SRCS)
	@MAKE -C $(FT_PRINTF_PATH) 

server.o: server.c
	@$(CC) $(FLAGS) -c server.c -o server.o $(INCLUDE)

client.o: client.c
	@$(CC) $(FLAGS) -c client.c -o client.o $(INCLUDE)

$(SERVER): $(FT_PRINTF) $(SERVER_OBJS)
	@$(CC) $(FLAGS) $(SERVER_OBJS) -o $(SERVER) $(FT_PRINTF) $(INCLUDE)
	@echo "Server Is Ready - run ./server"

$(CLIENT): $(FT_PRINTF) $(CLIENT_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_OBJS) -o $(CLIENT) $(FT_PRINTF) $(INCLUDE)
	@echo "Client is ready - run ./client"

#Bonus

bonus: $(FT_PRINTF) $(SERVER_BONUS) $(CLIENT_BONUS)

server_bonus.o: server_bonus.c
	@$(CC) $(FLAGS) -c server_bonus.c -o server_bonus.o $(INCLUDE)

client_bonus.o: client_bonus.c
	@$(CC) $(FLAGS) -c client_bonus.c -o client_bonus.o $(INCLUDE)

$(SERVER_BONUS): $(FT_PRINTF) $(SERVER_BONUS_OBJS)
	@$(CC) $(FLAGS) $(SERVER_BONUS_OBJS) -o $(SERVER_BONUS) $(FT_PRINTF) $(INCLUDE)
	@echo "Bonus Server Is Ready - run ./server_bonus"

$(CLIENT_BONUS): $(FT_PRINTF) $(CLIENT_BONUS_OBJS)
	@$(CC) $(FLAGS) $(CLIENT_BONUS_OBJS) -o $(CLIENT_BONUS) $(FT_PRINTF) $(INCLUDE)
	@echo "Bonus Client is ready - run ./client_bonus"

#Clean up

clean:
	@MAKE clean -C $(FT_PRINTF_PATH)
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	@$(RM) $(CLIENT_BONUS_OBJS) $(SERVER_BONUS_OBJS)
	@echo "Objects Are Now Deleted."

fclean: clean
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(SERVER_BONUS) $(CLIENT_BONUS)
	@$(RM) $(FT_PRINTF_PATH)$(FT_PRINTF_LIB)
	@echo "And libftprintf.a - Server - Client - Client_bonus - Server_bonus"

re: fclean all bonus
