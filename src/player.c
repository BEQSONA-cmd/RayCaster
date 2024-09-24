#include "../includes/game.h"

void init_player(t_player *player)
{
    player->x = WIDTH / 2;
    player->y = HEIGHT / 2;
    player->angle = PI / 2;

    player->key_up = false;
    player->key_down = false;
    player->key_left = false;
    player->key_right = false;

    player->key_left_rotate = false;
    player->key_right_rotate = false;
}

int move_player(t_game *game)
{
    t_player *player = &game->player;
    int speed = 3;
    float angle_speed = 0.03;
    float cos_angle = cos(player->angle);
    float sin_angle = sin(player->angle);

    if (player->key_left_rotate)
        player->angle -= angle_speed;
    if (player->key_right_rotate)
        player->angle += angle_speed;
    if (player->angle > 2 * PI)
        player->angle = 0;
    if (player->angle < 0)
        player->angle = 2 * PI;

    if (player->key_up)
    {
        player->x += cos_angle * speed;
        player->y += sin_angle * speed;
    }
    if (player->key_down)
    {
        player->x -= cos_angle * speed;
        player->y -= sin_angle * speed;
    }
    if (player->key_left)
    {
        player->x += sin_angle * speed;
        player->y -= cos_angle * speed;
    }
    if (player->key_right)
    {
        player->x -= sin_angle * speed;
        player->y += cos_angle * speed;
    }
    return (0);
}

void draw_wall(float height, float dist_to_wall, float start_x, t_game *game)
{
    int color = 0x00FF00;
    int start_y = (HEIGHT - height) / 2;
    int end = start_y + height;

    while (start_y < end)
    {
        put_pixel(start_x, start_y, color, game);
        start_y++;
    }
}

float distance(float x1, float y1, float x2, float y2)
{
    return sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int draw_line(t_player *player, t_game *game , float start_x , int i)
{
    float cos_angle = cos(start_x);
    float sin_angle = sin(start_x);
    float ray_x = player->x;
    float ray_y = player->y;

    while (!is_touching(ray_x, ray_y, game))
    {
        // put_pixel(ray_x, ray_y, 0xFF0000, game);
        ray_x += cos_angle;
        ray_y += sin_angle;
    }

    float dist_to_wall = distance(player->x, player->y, ray_x, ray_y);
    float height = (BLOCK_SIZE / dist_to_wall) * (WIDTH / 2);
    draw_wall(height, dist_to_wall, i, game);

    return (0);
}

int draw_loop(t_game *game)
{
    t_player *player = &game->player;
    move_player(game);
    clear_image(game);
    // draw_square(player->x, player->y, 5, 0x00FF00, game);
    // draw_map(game);

    float fraction = PI / 3 / WIDTH;
    float start_x = player->angle - PI / 6;
    int i = 0;
    while (i < WIDTH)
    {
        draw_line(player, game, start_x, i);
        start_x += fraction;
        i++;
    }

    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return (0);
}

