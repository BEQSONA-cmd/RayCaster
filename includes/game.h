#ifndef GAME_H
#define GAME_H

# define WIDTH 1280
# define HEIGHT 720

#include "./libft/libft.h"
#include "./mlx/mlx.h"
#include <stdio.h>

typedef struct s_game
{
    void *mlx;
    void *win;
} t_game;

#endif