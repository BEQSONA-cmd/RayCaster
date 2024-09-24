#include "../includes/game.h"

int main()
{
    t_game game;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "Hello world!");
    mlx_loop(game.mlx);
    return (0);
}