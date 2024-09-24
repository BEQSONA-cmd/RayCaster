#include "../includes/game.h"

void put_pixel(int x, int y, int color, t_game *render_game)
{
    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return ;

    int index = y * render_game->size_line + x * render_game->bpp / 8;
    
    render_game->data[index] = color & 0xFF;
    render_game->data[index + 1] = (color >> 8) & 0xFF;
    render_game->data[index + 2] = (color >> 16) & 0xFF;
}

int draw_square(int x, int y, int size, int color, t_game *render_game)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            put_pixel(x + i, y + j, color, render_game);
        }
    }
    return (0);
}

void clear_image(t_game *game, int color)
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            put_pixel(x, y, color, game);
        }
    }
}

void init_game(t_game *game)
{
    t_player player;
    init_player(&player);
    game->player = player;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}


int key_press(int keycode, t_game *game)
{
    if (keycode == W)
        game->player.key_up = true;
    if (keycode == S)
        game->player.key_down = true;
    if (keycode == A)
        game->player.key_left = true;
    if (keycode == D)
        game->player.key_right = true;
    return (0);
}

int key_release(int keycode, t_game *game)
{
    if (keycode == W)
        game->player.key_up = false;
    if (keycode == S)
        game->player.key_down = false;
    if (keycode == A)
        game->player.key_left = false;
    if (keycode == D)
        game->player.key_right = false;
    return (0);
}



int main()
{
    t_game game;
    init_game(&game);

    mlx_hook(game.win, 2, 1L<<0, key_press, &game);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game);
    mlx_loop_hook(game.mlx, move_player, &game);

    mlx_loop(game.mlx);
    return (0);
}