#include "minirt.h"

void	do_everything(t_scene scene)
{
	scene.x = 1000;
	scene.y = 500;
	scene.mlx_data.mlx = mlx_init();
	scene.mlx_data.win = mlx_new_window(scene.mlx_data.mlx, scene.x, scene.y, "My window name");
	mlx_loop(scene.mlx_data.mlx);
}
