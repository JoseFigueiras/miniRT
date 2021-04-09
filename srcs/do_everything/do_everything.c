#include "minirt.h"

static t_mlx	*get_mlx(t_res *res);
static t_img	*get_img(t_res *res, t_mlx *mlx);
static int		render_next_frame(t_scene *scene);

void	do_everything(t_scene scene)
{
	scene.mlx_data = get_mlx(scene.res);
	scene.img_data = get_img(scene.res, scene.mlx_data);
	if (!(mlx_loop_hook(scene.mlx_data->mlx, render_next_frame, &scene)))
		exit(0);
	mlx_loop(scene.mlx_data->mlx);
}

static int	render_next_frame(t_scene *scene)
{
	int		x;
	int		y;
	t_img	*img;
	t_mlx	*mlx;
	int		color;

	mlx = scene->mlx_data;
	img = scene->img_data;
	x = 0;
	while (x < scene->res->x)
	{
		y = 0;
		while (y < scene->res->y)
		{
			color = 0;
			color = get_pixel_color(x, y, *scene);
			//printf("x: %i, y: %i, color: %i\n", x, y, color);
			my_mlx_pixel_put(img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, img->img, 0, 0);
	return (1);
}

static t_mlx	*get_mlx(t_res *res)
{
	t_mlx	*mlx_data;

	mlx_data = malloc(sizeof(t_mlx));
	if (!mlx_data)
		return (NULL);
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, res->x, res->y, "MiniRT");
	return (mlx_data);
}

static t_img	*get_img(t_res *res, t_mlx *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_new_image(mlx->mlx, res->x, res->y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
									&img->line_length, &img->endian);
	return (img);
}
