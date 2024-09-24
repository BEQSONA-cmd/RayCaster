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

bool is_touching(float px, float py, t_game *game)
{
	int x = px / BLOCK_SIZE;
	int y = py / BLOCK_SIZE;

	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

int draw_square(int x, int y, int size, int color, t_game *render_game)
{
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y, color, render_game);
    for(int i = 0; i < size; i++)
        put_pixel(x, y + i, color, render_game);
    for(int i = 0; i < size; i++)
        put_pixel(x + size, y + i, color, render_game);
    for(int i = 0; i < size; i++)
        put_pixel(x + i, y + size, color, render_game);
    return (0);
}

void clear_image(t_game *game)
{
    for (int y = 0; y < HEIGHT; y++)
        for (int x = 0; x < WIDTH; x++)
            put_pixel(x, y, 0x000000, game);
}

char **get_map(void)
{
    char **map = malloc(sizeof(char *) * 11);
    map[0] = ft_strdup("111111111111111");
    map[1] = ft_strdup("100000000000001");
    map[2] = ft_strdup("100000000000001");
    map[3] = ft_strdup("100000000000001");
    map[4] = ft_strdup("100000010000001");
    map[5] = ft_strdup("100000000000001");
    map[6] = ft_strdup("100000000000001");
    map[7] = ft_strdup("100000000000001");
    map[8] = ft_strdup("100000000000001");
    map[9] = ft_strdup("111111111111111");
    map[10] = NULL;
    return (map);
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

int main()
{
    t_game game;
    init_game(&game);

    mlx_hook(game.win, 2, 1L<<0, key_press, &game);
    mlx_hook(game.win, 3, 1L<<1, key_release, &game);
    mlx_loop_hook(game.mlx, draw_loop, &game);

    mlx_loop(game.mlx);
    return (0);
}