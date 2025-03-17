NAME_SERVER = build/server
NAME_CLIENT = build/client
NAME_LIB = libft/libft.a

INCLUDES_H = -Iinc -Ilibft

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = src/server.c
SRC_CLIENT = src/client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: build $(NAME_SERVER) $(NAME_CLIENT) 

build:
	mkdir -p build

$(NAME_SERVER): $(NAME_LIB) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(NAME_LIB) -o $(NAME_SERVER)

$(NAME_CLIENT): $(NAME_LIB) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(NAME_LIB) -o $(NAME_CLIENT)

$(OBJ_SERVER): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_H) -c $< -o $@ 

$(OBJ_CLIENT): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_H) -c $< -o $@ 

$(NAME_LIB):
	make -C libft

clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	make -C libft fclean

fclean: clean
	rm -rf build

re: fclean all

.PHONY: all clean fclean re