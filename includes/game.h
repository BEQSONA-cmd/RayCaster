#ifndef GAME_H
#define GAME_H

# define WIDTH 1280
# define HEIGHT 720
# define BLOCK_SIZE 64

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define PI 3.14159265359

#include "./libft/libft.h"
#include "./mlx/mlx.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct s_player
{
    float x;
    float y;
    float angle;

    bool key_up;
    bool key_down;
    bool key_left;
    bool key_right;

    bool key_left_rotate;
    bool key_right_rotate;

} t_player;

typedef struct s_game
{
    void *mlx;
    void *win;
    void *img;
    char *data;
    int bpp;
    int size_line;
    int endian;
    int color;
    char **map;
    t_player player;
} t_game;


void clear_image(t_game *game);
int draw_square(int x, int y, int size, int color, t_game *game);

void init_player(t_player *player);
int move_player(t_game *game);
int draw_loop(t_game *game);
void put_pixel(int x, int y, int color, t_game *render_game);
void draw_map(t_game *game);
bool is_touching(float x, float y, t_game *game);
#endif