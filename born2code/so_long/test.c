#include "so_long_bonus.h"


int		update_display(t_game *game);

int		main(void)
{
	t_game	*game;
	int		img_width;
	int		img_height;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		return (1);

	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, 200, 200, "Test");

	// Load images
	game->img_player[0] = mlx_xpm_file_to_image(game->mlx, "./textures/t1.xpm", &img_width, &img_height);
	game->img_player[1] = mlx_xpm_file_to_image(game->mlx, "./textures/t2.xpm", &img_width, &img_height);
	game->img_black = mlx_xpm_file_to_image(game->mlx, "./textures/black.xpm", &img_width, &img_height);

	mlx_loop_hook(game->mlx, update_display, game);
	mlx_loop(game->mlx);
}

int		update_display(t_game *game)
{
	static int	frame = 0;

	// Clear the window
	//mlx_clear_window(game->mlx, game->mlx_window);

	// Display the appropriate image sprite based on the frame
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_black, 10, 10);
	if (frame == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_player[0], 10, 10);
    else if (frame == 3)
		 mlx_put_image_to_window(game->mlx, game->mlx_window, game->img_player[1], 10, 10);

	// Increment the frame counter
	frame++;
	if (frame == 10)
		frame = 0;

	return (0);
}