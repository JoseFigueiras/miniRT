#include "minirt.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx_data;
	int		x = 1600;
	int		y = 800;

	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, x, y, "My window name");
	mlx_loop(mlx_data.mlx);
}
