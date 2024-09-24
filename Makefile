NAME = game
CC = cc 

LFLAGS = -L./includes/mlx -lmlx -lXext -lX11 -lm -lz 
INCLUDE = includes/mlx/libmlx.a

SRC = src/main.c src/player.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

lib:
	@if [ ! -d "includes/mlx" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git ./includes/mlx; \
	fi
	make -C includes/mlx/

fclean_lib:
	make clean -C includes/mlx/

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(SRC) -o $(NAME) $(INCLUDE) $(LFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
