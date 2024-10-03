NAME = game 
CC = cc
OBJ = $(SRC:.c=.o)

LFLAGS = -L./includes/mlx -lmlx -lXext -lX11 -lm -lz
INCLUDES = includes/mlx/libmlx.a
SRC = src/main.c src/player.c

all: $(NAME)

mlx:
	git clone https://github.com/42Paris/minilibx-linux.git ./includes/mlx
	make -C ./includes/mlx

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(INCLUDES) $(LFLAGS)

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
