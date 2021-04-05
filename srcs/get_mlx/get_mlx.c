#include "minirt.h"

t_mlx	*get_mlx(t_res *res)
{
	t_mlx	*mlx_data;

	mlx_data = malloc(sizeof(t_mlx));
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, res->x, res->y, "MiniRT");
	return (mlx_data);
}
