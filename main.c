#include <stdio.h>
#include <math.h>
#include "minilibx/mlx.h"

int	main()
{
	double	a = 3.0;
	void	*ptr;
	void	*win;
	int		i, j;

	ptr = mlx_init();
	win = mlx_new_window(ptr, 1000, 500, "Hello World!");
	//printf("cos(3.0) = %f\n", cos(a));
	i = 0; j = 0;
	while (1)
	{
		mlx_pixel_put(ptr, win, i, j, i + j);
		i++;
		j++;
	}
	mlx_clear_window(ptr, win);
	return (0);
}
