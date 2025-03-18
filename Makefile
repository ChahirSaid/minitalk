NAME_1					= server
NAME_2					= client
NAME_3					= server_bonus
NAME_4					= client_bonus

CC						= cc
CFLAGS					= -Wall -Wextra -Werror

SRC						= mandatory/server.c mandatory/client.c
BONUS_SRC				= bonus/server_bonus.c bonus/client_bonus.c

OBJ						= $(SRC:.c=.o)
BONUS_OBJ				= $(BONUS_SRC:.c=.o)
SERVER_OBJ				= mandatory/server.o
CLIENT_OBJ				= mandatory/client.o
SERVER_BONUS_OBJ		= bonus/server_bonus.o
CLIENT_BONUS_OBJ		= bonus/client_bonus.o

LIBFT_PATH				= ./libft
LIBFT					= $(LIBFT_PATH)/libft.a

HEADER					= ./includes/minitalk.h
BONUS_HEADER			= ./includes/minitalk_bonus.h

all: $(NAME_1) $(NAME_2)
bonus: $(NAME_3) $(NAME_4)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME_1): $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(NAME_1)
$(NAME_2): $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(NAME_2)
$(NAME_3): $(BONUS_OBJ) $(LIBFT) $(BONUS_HEADER)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) $(LIBFT) -o $(NAME_3)
$(NAME_4): $(BONUS_OBJ) $(LIBFT) $(BONUS_HEADER)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) $(LIBFT) -o $(NAME_4)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME_1) $(NAME_2) $(NAME_3) $(NAME_4)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
