#include "../includes/game.h"

void init_player(t_player *player)
{
    player->x = WIDTH / 2;
    player->y = HEIGHT / 2;
    player->key_up = false;
    player->key_down = false;
    player->key_left = false;
    player->key_right = false;
}

int move_player(t_game *game)
{
    t_player *player = &game->player;
    int speed = 5;
    if (player->key_up)
        player->y -= speed;
    if (player->key_down)
        player->y += speed;
    if (player->key_left)
        player->x -= speed;
    if (player->key_right)
        player->x += speed;
    
    clear_image(game, 0x000000);
    draw_square(player->x, player->y, 10, 0xFF0000, game);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);

    return (0);
}
