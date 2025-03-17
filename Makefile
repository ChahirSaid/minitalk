NAME			= server
NAME_1			= client

CC				= cc
CFLAGS			= -Wall -Wextra -Werror

SRC				= mandatory/server.c mandatory/client.c

OBJ				= $(SRC:.c=.o)
SERVER_OBJ		= mandatory/server.o
CLIENT_OBJ		= mandatory/client.o

LIBFT_PATH		= ./libft
LIBFT			= $(LIBFT_PATH)/libft.a

HEADER			= ./includes/minitalk.h

all: $(NAME) $(NAME_1)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(NAME)
$(NAME_1): $(OBJ) $(LIBFT) $(HEADER)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(NAME_1)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME) $(NAME_1)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re bonus
