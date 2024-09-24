#include "../includes/game.h"

// our own function to put a pixel in the image
void put_pixel(int x, int y, int color, t_game *render_game)
{
    if(x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return ;

    int index = y * render_game->size_line + x * render_game->bpp / 8;
    
    render_game->data[index] = color & 0xFF;
    render_game->data[index + 1] = (color >> 8) & 0xFF;
    render_game->data[index + 2] = (color >> 16) & 0xFF;
}

void clear_image(t_game *game)
{
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            put_pixel(x, y, 0x000000, game);
}

// utils functions
char **get_map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    map[0] = "111111111111111";
    map[1] = "100000000000001";
    map[2] = "100000000000001";
    map[3] = "100000000000001";
    map[4] = "100000000000001";
    map[5] = "100000000000001";
    map[6] = "100000000000001";
    map[7] = "100000000000001";
    map[8] = "100000000000001";
    map[9] = "111111111111111";
    map[10] = NULL;
    return (map);
}

float distance(float x, float y)
{
    return sqrt(x * x + y * y);
}

float fish_eye_correction(float x1, float y1, float x2, float y2, t_game *game)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    float angle = atan2(delta_y, delta_x) - game->player.angle;
    float fix_dist = distance(delta_x, delta_y) * cos(angle);
    return (fix_dist);
}

bool is_touching(float px, float py, t_game *game)
{
	int x = px / BLOCK_SIZE;
	int y = py / BLOCK_SIZE;

	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

void draw_square(int x, int y, int size, int color, t_game *render_game)
{
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y, color, render_game);
    for(int i = 0; i < size; i++)
        put_pixel(x, y + i, color, render_game);
    for(int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, render_game);
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, render_game);
}

void draw_map(t_game *game)
{
    char **map = game->map;
    int color = 0x0000FF;
    for (int y = 0; map[y]; y++)
        for (int x = 0; map[y][x]; x++)
            if (map[y][x] == '1')
                draw_square(x * BLOCK_SIZE, y * BLOCK_SIZE, BLOCK_SIZE, color, game);
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
    if (keycode == LEFT)
        game->player.key_left_rotate = true;
    if (keycode == RIGHT)
        game->player.key_right_rotate = true;
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
    if (keycode == LEFT)
        game->player.key_left_rotate = false;
    if (keycode == RIGHT)
        game->player.key_right_rotate = false;
    return (0);
}


// raycasting functions
void draw_line(t_player *player, t_game *game , float start_x , int i)
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

    float dist_to_wall = fish_eye_correction(player->x, player->y, ray_x, ray_y , game);
    float height = (BLOCK_SIZE / dist_to_wall) * (WIDTH / 2);
    int start_y = (HEIGHT - height) / 2;
    int end = start_y + height;
    while(start_y < end)
    {
        put_pixel(i, start_y, 0x00FF00, game);
        start_y++;
    }
}

int draw_loop(t_game *game)
{
    t_player *player = &game->player;
    move_player(player);
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

void init_game(t_game *game)
{
    t_player player;
    init_player(&player);
    game->map = get_map();
    game->player = player;
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int main(void)
{
    t_game game;
    init_game(&game);

    mlx_hook(game.win, 2, 1L<<0, key_press, &game);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game);
    mlx_loop_hook(game.mlx, draw_loop, &game);

    mlx_loop(game.mlx);
    return (0);
}
